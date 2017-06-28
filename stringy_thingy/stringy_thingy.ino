#include <Arduino.h>
#include <stdint.h>
#include "Linduino.h"
#include "UserInterface.h"
#include "math.h"

// Pin Map
const uint8_t M3A  = 11;
const uint8_t M3B  = 12;
const uint8_t M4A  = 9;
const uint8_t M4B  = 10;
const uint8_t DIR_EN = 8;

const uint8_t PWM0B = 5;
const uint8_t PWM0A = 6;


// Function Decoration
void print_title();                             // Print the title block
void print_prompt();                            // Prompt the user for an input command
void init_16_bit_PWM();                         // Initializes Pin 9 and 10 for 16-bit PWM
void pwm_16_bit(uint8_t pin, uint16_t duty);    // Sets the 16-bit PWM
void menu_1_select_dac(int16_t *selected_dac);  // Selects DAC
void menu_2_set_duty(int8_t selected_dac);      // Sets the Duty Cycle
uint16_t LTC2645_voltage_to_pwm_code(float dac_voltage, float fullScaleVoltage, int8_t pwmBitResolution);   // Converts voltage to PWM code(DAC Code)
void python_program();                          // Used for the corresponding Python program
int16_t prompt_voltage_or_code();               // Prompts for voltage or code
uint16_t get_voltage(float fullScaleVoltage, int8_t pwmBitResolution);  // Obtains voltage from user
uint16_t get_code();                            // Obtains code from user
void test();

// Global Variable
float fullScale = 2.5;  //! Full Scale Voltage
float percentDutyCycle[4] = {0.0,0.0,0.0,0.0};

//! Used to keep track to print voltage or print code
enum
{
  PROMPT_VOLTAGE = 0, /**< 0 */
  PROMPT_CODE = 1     /**< 1 */
};


#define loopmax 255
unsigned int x;
unsigned char y;
unsigned char loopcount = 5;
unsigned char m3countin = 10;
unsigned char m4countin = 10;
unsigned char m3count = 10;
unsigned char m4count = 10;
unsigned char m3dir = 0;
unsigned char m4dir = 0;

unsigned char mstate;

//! Initialize Linduino
void setup()
{

  Serial.begin(115200);   // Initialize the serial port to the PC

  // Goes into Python Mode if 'z' is sent by the Python program
  char python_char = 'x';
  for (int i = 0; i <= 50; i++)
  {
    if (Serial.available() > 0)
      python_char = Serial.read();
    if ((python_char == 'Z') || (python_char == 'z') )
//      python_program();
    delay(30);
  }

  pinMode(M3A,OUTPUT);
  pinMode(M3B,OUTPUT);
  pinMode(M4A,OUTPUT);
  pinMode(M4B,OUTPUT);
  pinMode(DIR_EN,OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);

  analogWrite(PWM0A, 64);
  analogWrite(PWM0B, 64);
PORTB = B00000000; // Motors off initially

for(char q = 1; q>0; --q)
  {
  mstate = B00010100; //both
  PORTB = mstate;
//  PORTB = B00010000;
//  PORTB = B00000100;
    PORTB |= B00000010;
    PORTB &= B11111011;


  delay(25);
  mstate = B00001010; //both
  PORTB = mstate;
//  PORTB = B00001000;
//  PORTB = B00000010;
    PORTB |= B00000100;
    PORTB &= B11111011;

  delay(25);
  }
  
  
  for(char q = 1; q>0; --q)
  {
    mstate &= B11111011;
    mstate |= B00000010;
    PORTB = mstate;
    delay(25);
    mstate &= B11111101;
    mstate |= B00000100;
    PORTB = mstate;
    delay(25);
  }
  
  
  analogWrite(PWM0A, 10);
  analogWrite(PWM0B, 10);
}

//! Repeats Linduino loop
void loop()
{
delayMicroseconds(200);

--m3count;
if(!m3count)
  {
  if(!m3dir)
    {
    mstate = mstate | B00000010;
    mstate = mstate & B11111011;
    PORTB = mstate;
    m3dir = 1;
    }
  else
    {
    mstate = mstate | B00000100;
    mstate = mstate & B11111101;
    PORTB = mstate;
    m3dir = 0;
    }
  m3count = m3countin;
  }
  
--m4count;
if(!m4count)
  {
  if(!m4dir)
    {
    mstate = mstate | B00001000;
    mstate = mstate & B11101111;
    PORTB = mstate;
    m4dir = 1;
    }
  else
    {
    mstate = mstate | B00010000;
    mstate = mstate & B11110111;
    PORTB = mstate;
    m4dir = 0;
    }
  m4count = m4countin;
  }
  
--loopcount;
if(!loopcount)
  {
  loopcount = loopmax; // reset counter
  x = analogRead(0);  // read pot
  y = (unsigned char) (x/4); // scale to 8 bits
  analogWrite(PWM0A, y); // set motor PWM
  analogWrite(PWM0B, y);
  x = analogRead(1);
  m3countin = (unsigned char)(x/4);
  x = analogRead(2);
  m4countin = (unsigned char)(x/4);
  }
}
