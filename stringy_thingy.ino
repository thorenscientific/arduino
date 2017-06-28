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

  analogWrite(PWM0A, 128);
  analogWrite(PWM0B, 128);


}

//! Repeats Linduino loop
void loop()
{
//PORTD = B10101000; // sets digital pins 7,5,3 HIGH

PORTB = B00010100;
delay(25);

PORTB = B00001010;
delay(25);



}
