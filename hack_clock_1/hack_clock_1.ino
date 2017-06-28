/*
hack_clock_1

* four digit clock.  Time and stock price are set through the serial port.
* Messages consist of the letter T followed by ten digit time (as seconds since Jan 1 1970)
* followed by four digits of LLTC stock price ($$.cc)
* you can send the text on the next line using Serial Monitor to set the clock to noon Jan 1 2010 and LLTC to $29.45
T12623472002945 
 
Use Direct Port Manipulation To turn on LEDs
*  C5  Segment A
*  C4  Segment B
*  C3  Segment C
*  C2  Segment D
*  C1  Segment E
*  C0  Segment F
*  B4  Segment G
*  B0  Cathode Hr 10's
*  B1  Cathode Hr 1's
*  B2  Cathode Min 10's
*  B3  Cathode Min 1's
*  B4  Decimal Point  **New addition**

* PM dot is digital pin 3. Active High (1 = LED on).
* Top Colon dot is digital pin 4. Active High (1 = LED on). On only for time
* Bottom Colon dot is digital pin 5. Active High (1 = LED on). On for time or price
 */
 
#include "TimeRich.h"  

#define TIME_MSG_LEN  15   // time sync to PC is HEADER followed by unix time_t as ten ascii digits
#define TIME_HEADER  'T'   // Header tag for serial time sync message 

//#define SERIALECHO // Echo every character. This will look a lot nicer with a proper buffer / parser
                      // arrangement.
//#define TESTDISP

const int mux_delay=3;  //number of ms between refreshes
const int ticker_delay=3500;  //number of ms to display the stock ticker
const int price_delay=3500;  //number of ms to display the stock price
const int pm_pin=3;        //pin number of PM dot
const int top_dot_pin=4;        //pin number of top colon dot
const int bot_dot_pin=5;        //pin number of bot colon dot

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
  B00010000,    // L
  B00000000,    // t
  B00010000,     // c
  B00010000     // blank
};

const byte c_digits[] = {
  B00000000,    // 0#
  B00100111,    // 1#
  B00001001,    // 2#
  B00000011,    // 3#
  B00100110,    // 4#   
  B00010010,    // 5#  
  B00010000,    // 6#
  B00000111,    // 7# 
  B00000000,    // 8#
  B00000010,    // 9#
  B00111000,    // L#
  B00111000,    // t#
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
unsigned long next_refresh = 2;  // Time for next LED refresh
unsigned long t_start_price_mode = 0;  // Time for starting price mode (assumes we are already in stock mode)
unsigned long t_end_stock_mode = 0;  // Time for leaving stock mode
byte lltc[] = {'2','9','4','5'};          // LTC stock price - come on Rich, can't you be a little bit more optimistic for a default price??
int stock_mode = 0;              // Binary flag. =1 if stock name or the price is being displayed
int price_mode = 0;              // Binary flag. =1 if price is being displayed


void setup() {    
  Serial.begin(9600);
  setSyncProvider( requestSync);  //set function to call when sync required
  next_refresh =  millis();
  // initialize the digital pins as outputs.
  DDRB = B11111111;        // Configure port B (pins 8-13) as output
  DDRC = B11111111;        // Configure port C (pins A0-A5) as output
  pinMode(pm_pin, OUTPUT);      // Indicator LED for PM
  pinMode(top_dot_pin, OUTPUT);      // Indicator LED for top colon dot
  pinMode(bot_dot_pin, OUTPUT);      // Indicator LED for bottom colon dot
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
//  if (millis() > next_refresh) refresh_led();    // Move to next led digit

// Rich, looks like the serial routine has 128 character buffer, so it should
// be safe to put in millisecondish delays in the main loop. You might try refreshing,
// waiting a few ms, then blanking, then checking serial.available.
// Also, I see a little hiccup once a second, perhaps due to updating time once a second.
// Don't you really only have to do this once a minute? Detect the minute change, then update.


  delay(1); refresh_led();
  if (second() != ss) update_time();              // Update time 
  if (stock_mode) update_stock_mode();            // Handle Stock Mode routine  
  if(Serial.available() ) processSyncMessage();  // Read serial input message if there is one
#endif
}


void refresh_led () {
  // Move to the next led digit
  
// You could optimize this a bit by making an array of the actual data to send to the display, rather than doing a
// double lookup. probably doesn't matter that much.
  
  next_refresh += mux_delay;
  if (++cur_dig >3)    cur_dig = 0;      // Increment current digit and wrap around to 0 if necessary
  PORTB = 0;  //Blank for a bit...
  PORTC = c_digits[ disp_dig[ cur_dig ] ];                             // update port C   
  PORTB = b_digits[ disp_dig[ cur_dig ] ] | digit_mask[ cur_dig ];     // update port B
}


void update_time()  {
  // Read current time and put into the disp_dig array
  time_t t = now(); // store the current time in time variable t 
  hh = hour(t);          // returns the hour for the given time t
  mm = minute(t);        // returns the minute for the given time t
  ss = second(t);        // returns the seconds for the given time t
  if ( !stock_mode) {    // only update digit display if we are in time mode
    put_time_in_display_array();
#ifdef SERIALECHO
    Serial.print(hh);
    Serial.print(mm);
    Serial.println(ss);
#endif
  }
}


void update_stock_mode()   {
  // Check to see if it is time to jump to price mode or leave stock mode
  if (!price_mode && millis() > t_start_price_mode)     { // start price mode
    t_end_stock_mode = millis() + price_delay;
    price_mode=1;
    digitalWrite(pm_pin, LOW);       // clear PM dot
    digitalWrite(top_dot_pin, LOW);  // clear top dot in colon
    digitalWrite(bot_dot_pin, HIGH);  // set bottom dot in colon
    // Put stock price in disp_dig array
    disp_dig[0] = lltc[0];      // set $ 10's
    disp_dig[1] = lltc[1];      // set $ 1's
    disp_dig[2] = lltc[2];      // set c 10's
    disp_dig[3] = lltc[3];      // set c 1's
  };
  if (price_mode && millis() > t_end_stock_mode)        { // end stock mode
    stock_mode=0;
    price_mode=0;
    put_time_in_display_array();
  };  
}


void start_stock_mode()   {
  // Just received new stock price.  Start up stock mode
  t_start_price_mode = millis() + ticker_delay;
  stock_mode=1;
  digitalWrite(pm_pin, LOW);       // clear PM dot
  digitalWrite(top_dot_pin, LOW);  // clear top dot in colon
  digitalWrite(bot_dot_pin, LOW);  // clear bottom dot in colon
  // Put stock ticker in disp_dig array
  disp_dig[0] = 10;      // L
  disp_dig[1] = 10;      // L
  disp_dig[2] = 11;      // t
  disp_dig[3] = 12;      // c
}


void put_time_in_display_array() {   // Convert time to digit format and place it in disp_dig array
    int hh_tmp = 0;    // temporary variable for storing current hour in 12-hour format
    digitalWrite(top_dot_pin, HIGH);  // set top dot in colon
    digitalWrite(bot_dot_pin, HIGH);  // set bottom dot in colon
    if (hh > 12) {
      digitalWrite(pm_pin, HIGH);  // set PM dot
      hh_tmp = hh - 12;       // convert to 12 hour time number
    }
    else {
      digitalWrite(pm_pin, LOW);  // clear PM dot
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

void processSyncMessage() {
  // if time sync available from serial port, update time and return true
  
// This is where you might want to queue up the entire command. A "T" could reset the buffer pointer to zero
// and record the present millis() value. After the right number of characters has been received, check to see that
// it took less than a second for all of the characters to come in (a grossly large time.) If it did take longer than a
// a second, skip the command and reset to zero. A simple checksum might avoid embarassing (unintentional) errors.   
  
  while(Serial.available() >=  TIME_MSG_LEN ){  // time message consists of a header and ten ascii digits, four stock price digits
    char c = Serial.read() ;
    if( c == TIME_HEADER ) {       
      time_t pctime = 0;
      for(int i=0; i < TIME_MSG_LEN - 5; i++){   
        c = Serial.read();     
        if( c >= '0' && c <= '9'){   
          pctime = (10 * pctime) + (c - '0') ; // convert digits to a number    
        }
      }
      c = Serial.read(); 
      lltc[0] = c-'0';    // convert price digits to numbers
      c = Serial.read();
      lltc[1] = c-'0';
      c = Serial.read();
      lltc[2] = c-'0';
      c = Serial.read();
      lltc[3] = c-'0';
      setTime(pctime);   // Sync Arduino clock to the time received on the serial port
      start_stock_mode();            // Start Stock Mode
    }  
  }
}


time_t requestSync()
{  
  return 0;       // This routine is required by the Time library, but we don't use it.
}


  

