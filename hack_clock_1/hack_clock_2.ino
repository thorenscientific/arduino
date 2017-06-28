/*
hack_clock_2

* Originally created by Rich, improved by Mark, and further modified by Rich
* four digit clock.  Time and stock price are set through the serial port.
* Messages consist of the letter T followed by ten digit time (as seconds since Jan 1 1970)
* followed by four digits of LLTC stock price ($$.cc)
* followed by three digits which are the checksum of the first 14 digits
* you can send the text on the next line using Serial Monitor to set the clock to noon Jan 1 2010 and LLTC to $29.45 
T12623472002945047
T12623471852945059  11:59AM shows transition to PM
 
Use Direct Port Manipulation To turn on LEDs
*  C5  Segment A
*  C4  Segment B
*  C3  Segment C
*  C2  Segment D
*  C1  Segment E
*  C0  Segment F
*  B4  Segment G
*  B5  Decimal Point  
*  B0  Cathode Hr 10's
*  B1  Cathode Hr 1's
*  B2  Cathode Min 10's
*  B3  Cathode Min 1's

 */
 
#include <TimeRich.h>  

#define TIME_HEADER  'T'   // Header tag for serial time sync message 

//#define SERIALECHO // Echo every character. This will look a lot nicer with a proper buffer / parser
                      // arrangement.
//#define TESTDISP

const int ticker_delay=3500;  //number of ms to display the stock ticker
const int price_delay=3500;  //number of ms to display the stock price

const byte b_digits[] = {
  B00010000,    // 0
  B00010000,    // 1
  B00000000,    // 2  
  B00000000,    // 3
  B00000000,    // 4
  B00000000,    // 5   
  B00000000,    // 6
  B00010000,    // 7
  B00000000,    // 8 
  B00000000,    // 9
  B00110000,    // L
  B00110000,    //B00100000,    // t
  B00110000,    // c
  B00110000     // blank
};

const byte c_digits[] = {
  B00000000,    // 0#
  B00100111,    // 1#
  B00001001,    // 2#
  B00000011,    // 3#
  B00100110,    // 4#   
  B00010010,    // 5#  
  B00010000,    // 6#
  B00000110,    // 7# 
  B00000000,    // 8#
  B00000010,    // 9#
  B00111000,    // L#
  B00011100,    //B00111000,    // t#
  B00011000,     // c#
  B00111111     // blank#
};

const byte digit_mask[] = {
  B00001000,  // Hr 10's
  B00000100,  // Hr 1's
  B00000010,  // Min 10's
  B00000001,  // Min 1's
};

int hh = 12;          // Current Time Hours (24hour format)
int mm = 45;          // Current Time Minutes
int ss = 13;          // Current Time Seconds
int disp_dig[] = {1,2,3,4};    // What's currently displayed:  HH:MM  (refresh routine blindly sends this to LEDs in all modes)
int cur_dig = 0;               // Current digit being displayed. 0=Hr 10s, 1=Hr 1's, 2=Min 10's, 3=Min 1's
unsigned long t_start_price_mode = 0;  // Time for starting price mode (assumes we are already in stock mode)
unsigned long t_end_stock_mode = 0;  // Time for leaving stock mode
byte lltc[] = {'3','3','4','8'};          // LTC stock price 
int stock_mode = 0;              // Binary flag. =1 if stock name or the price is being displayed
int price_mode = 0;              // Binary flag. =1 if price is being displayed
unsigned long t_ser_string_start = 0;   // Time for start of a serial input command
int ser_ptr = 99;                        // Pointer for the last digit read in a serial input command
int ser_string[17];              // Array for holding serial string (saved as an integer for each digit 0-9)
int am_flag = 0;                    // High if the time is AM, low if the time is PM

void setup() {    
  Serial.begin(9600);
  setSyncProvider( requestSync);  //set function to call when sync required
  // initialize the digital pins as outputs.
  DDRB = B11111111;        // Configure port B (pins 8-13) as output
  DDRC = B11111111;        // Configure port C (pins A0-A5) as output
}


void loop() {
#ifdef TESTDISP
// Simple reality check
    disp_dig[0] = 0;      // set $ 10's
    disp_dig[1] = 1;      // set $ 1's
    disp_dig[2] = 2;      // set c 10's
    disp_dig[3] = 3;      // set c 1's
    delay(1);
    refresh_led();
#else
// Main loop. This must be very tight to minimize flicker
//  delay(2); 
  refresh_led();
  delayMicroseconds(700);
  if (minute() != mm) update_time();              // Update time 
  if (stock_mode) update_stock_mode();            // Handle Stock Mode routine  
#endif
}


void refresh_led () {
  // Move to the next led digit
  
// You could optimize this a bit by making an array of the actual data to send to the display, rather than doing a
// double lookup. probably doesn't matter that much.
  
  if (++cur_dig >3)    cur_dig = 0;      // Increment current digit and wrap around to 0 if necessary
  PORTB = B00110000;  //Blank digits
  PORTC = B00111111;  // Blank
  delayMicroseconds(1000);  //Leave digits blank while changing segments and checking serial port
  PORTC = c_digits[ disp_dig[ cur_dig ] ];       // update port C segments
  if(Serial.available() ) ReadSerialData();  // Read serial input message if there is one  
  byte b_tmp = b_digits[ disp_dig[ cur_dig ] ] | digit_mask[ cur_dig ];
  if (price_mode) {
    if (cur_dig >1) {
      b_tmp |= B00100000;   // In price mode, blank the pm and top colon dots
    }
  }
  if (cur_dig == 3) {
    if (am_flag) {
      b_tmp |= B00100000;   // If it is AM, blank the PM dot
    }
  }
  PORTB = b_tmp;     // enable LED segment
}


void update_time()  {
  // Read current time and put into the disp_dig array
  time_t t = now(); // store the current time in time variable t 
  hh = hour(t);          // returns the hour for the given time t
  mm = minute(t);        // returns the minute for the given time t
//  ss = second(t);        // returns the seconds for the given time t
  if ( !stock_mode) {    // only update digit display if we are in time mode
    put_time_in_display_array();
#ifdef SERIALECHO
    Serial.print(hh);
    Serial.print(mm);
//    Serial.println(ss);
#endif
  }
}


void update_stock_mode()   {
  // Check to see if it is time to jump to price mode or leave stock mode
  if (!price_mode && millis() > t_start_price_mode)     { // start price mode
    t_end_stock_mode = millis() + price_delay;
    price_mode=1;
    // Put stock price in disp_dig array
    disp_dig[0] = lltc[0];      // set $ 10's
    disp_dig[1] = lltc[1];      // set $ 1's
    disp_dig[2] = lltc[2];      // set c 10's
    disp_dig[3] = lltc[3];      // set c 1's
  };
  if (price_mode && millis() > t_end_stock_mode)        { // end stock mode
    stock_mode=0;
    price_mode=0;
    update_time();
  };  
}


void start_stock_mode()   {
  // Just received new stock price.  Start up stock mode
  t_start_price_mode = millis() + ticker_delay;
  stock_mode=1;
  // Put stock ticker in disp_dig array
  disp_dig[0] = 10;      // L
  disp_dig[1] = 10;      // L
  disp_dig[2] = 11;      // t
  disp_dig[3] = 12;      // c
}


void put_time_in_display_array() {   // Convert time to digit format and place it in disp_dig array
    int hh_tmp = 0;    // temporary variable for storing current hour in 12-hour format
    am_flag = isAM();            // PM
    if (hh > 12) {
      hh_tmp = hh - 12;       // convert to 12 hour time number
    }
    else {
      hh_tmp = hh;       // convert to 12 hour time number
    };    
    if (hh_tmp > 9) { 
      disp_dig[0] = 1;            // set Hr 10's to 1
      disp_dig[1] = hh_tmp - 10;  // set Hr 1's
    }
    else {
      disp_dig[0] = 13;           // set Hr 10's to Blank
      disp_dig[1] = hh_tmp;       // set Hr 1's
    };   
    disp_dig[2] = mm / 10;        // set Min 10's
    disp_dig[3] = mm % 10;        // Set Min 1's
}

void ReadSerialData() {
  // Read and parse any data in the Serial Port Input Buffer
  while(Serial.available()) {
    char c = Serial.read();
    if ( c == TIME_HEADER ) {   // Start of new serial string
      ser_ptr = 0;              // Reset the serial pointer
      t_ser_string_start = millis();  // Stamp the time when the new serial string started
    }
    else if ( c < '0' || c > '9' ) {   // Invalid character
      ser_ptr = 99;             // Make the serial pointer an invalid number
    }
    else if ( ser_ptr < 17 ) {   // Valid character and valid pointer value
      ser_string[ser_ptr] = c-'0';   // convert character to integer and save in the array
      ser_ptr = ser_ptr+1;
      if (ser_ptr == 17) {      // 17 valid digits have been read. Check to see if the string is valid.
        CheckForValidSerialString();
      }
    }
  }
}


void CheckForValidSerialString() {
// Checks to see if the 17 digits in ser_string are valid. First calculates how long it took for the serial string to be read in,
// and ensures it is less than 1000ms.  Next, it calcuates the sum of the first 14 digits and compares that to the three digit
// checksum.  If they match, then the serial command is valid and the pcTime is set and we start Stock Mode.

  ser_ptr = 99; //Make the serial pointer an invalid number
  if ( (millis() - t_ser_string_start) > 1000 ) {    // Took too long to read in serial string. Ignore result.
    return;
  }
  int checksum1 = 0;
  int checksum2 = 0;
  for (int i=0; i < 14; i++) {  // Calculate sum of first fourteen digits
    checksum1 = checksum1 + ser_string[i];
  }
  // Calculate the three digit number in digits 14, 15, 16
  checksum2 = 100*ser_string[14] + 10*ser_string[15] + ser_string[16];
  if (checksum1 == checksum2) {   //Valid string
    time_t pctime = 0;
    for (int i=0; i < 10 ; i++) {  // Convert time data to a ten digit number
      pctime = (10 * pctime) + ser_string[i] ;
    }
    lltc[0] = ser_string[10];   
    lltc[1] = ser_string[11]; 
    lltc[2] = ser_string[12];   
    lltc[3] = ser_string[13]; 
    setTime(pctime);   // Sync Arduino clock to the time received on the serial port
    start_stock_mode();            // Start Stock Mode
  } 
}


time_t requestSync()
{  
  return 0;       // This routine is required by the Time library, but we don't use it.
}


  

