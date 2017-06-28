/**
 * @file       cam.c
 * @brief      gameboy camera interface for AT90S4433
 *             see the ccd device doc to understand the api: M64282FP.pdf
 * 
 * @author     Laurent Saint-Marcel (lstmarcel@yahoo.fr)
 * @date       2005/07/05
 */

#include <io.h>

#include "cam.h"
#include "camCom.h"
#include "adc.h"
#include "uart.h"

#define CAM_DATA_PORT     PORTB
#define CAM_DATA_DDR      DDRB

#define CAM_READ_PIN      PIND
#define CAM_LED_READ_DDR  DDRD
#define CAM_LED_PORT      PORTD

// CAM_DATA_PORT
#define CAM_CLOCK_BIT 0
#define CAM_SIN_BIT   3
#define CAM_LOAD_BIT  2
#define CAM_RESET_BIT 1
#define CAM_START_BIT 4
// CAM_READ_PIN
#define CAM_READ_BIT  7
// CAM_LED_PORT
#define CAM_LED_BIT   6
// PORT C: Analogic/digital converter
#define CAM_ADC_PIN   5


volatile unsigned char camReadPixelDone=FALSE;
// default value for registers
unsigned char camReg1[8]={ 0x80, 0x03, 0x00, 0x30, 0x01, 0x00, 0x01, 0x21 };

unsigned char camMode       = CAM_MODE_STANDARD;
unsigned char camClockSpeed = 0x0A;

unsigned char camPixMin =0;
unsigned char camPixMax =0xFF;
unsigned char camCompBuf=0;
unsigned char camCompI  =0;

//############################################################################
//####   PRIVATE FUNCTION : Communication with the AR chip                ####
//############################################################################
// cbi(port, bitId) = clear bit(port, bitId) = Set the signal Low
// sbi(port, bitId) = set bit(port, bitId) = Set the signal High
// Delay used between each signal sent to the AR (four per xck cycle).
void camStepDelay(){
  	unsigned char u=camClockSpeed;
	while(u--) {__asm__ __volatile__ ("nop");}
}
// Set the clock signal Low
inline void camClockL()
{
	cbi(CAM_DATA_PORT, CAM_CLOCK_BIT);
}
// Set the clock signal High
inline void camClockH()
{
	sbi(CAM_DATA_PORT, CAM_CLOCK_BIT);
}

// Sends a 'reset' pulse to the AR chip.
void camResetAR()
{
 camClockL(); // clock low
 cbi(CAM_DATA_PORT, CAM_RESET_BIT);
 camStepDelay();
 camStepDelay();

 camClockH(); // clock low	
 camStepDelay();
 camStepDelay();
 sbi(CAM_DATA_PORT, CAM_RESET_BIT);
}

// Sets one of the 8 8-bit registers in the AR chip.
void camSetRegAR(unsigned char regaddr, unsigned char regval)
{
 unsigned char bitmask;

 // Write 3-bit address.
 for(bitmask = 4; bitmask >= 1; bitmask >>= 1){
  camClockL();
  camStepDelay();
  cbi(CAM_DATA_PORT, CAM_LOAD_BIT);
  if(regaddr & bitmask) sbi(CAM_DATA_PORT, CAM_SIN_BIT);
  else cbi(CAM_DATA_PORT, CAM_SIN_BIT);
  camStepDelay();

  camClockH();
  camStepDelay();
  cbi(CAM_DATA_PORT, CAM_SIN_BIT);
  camStepDelay();
 }

 // Write 7 most significant bits of 8-bit data.
 for(bitmask = 128; bitmask >= 2; bitmask>>=1){
  camClockL();
  camStepDelay();
  if(regval & bitmask) sbi(CAM_DATA_PORT, CAM_SIN_BIT);
  else cbi(CAM_DATA_PORT, CAM_SIN_BIT);
  camStepDelay();

  camClockH();
  camStepDelay();
  cbi(CAM_DATA_PORT, CAM_SIN_BIT);
  camStepDelay();
 }

 // Write LSB of data along with 'load' signal and the rest of xck.
 camClockL();
 camStepDelay();
 if(regval & 1) sbi(CAM_DATA_PORT, CAM_SIN_BIT);
 else cbi(CAM_DATA_PORT, CAM_SIN_BIT);
 camStepDelay();

 camClockH();
 camStepDelay();
 sbi(CAM_DATA_PORT, CAM_LOAD_BIT); // load asserted (on falling edge of xck)
 camStepDelay();
}

// Sends a 'start' pulse to the AR chip.
void camStartAR()
{
 camClockL();
 camStepDelay();
 cbi(CAM_DATA_PORT, CAM_SIN_BIT);
 cbi(CAM_DATA_PORT, CAM_LOAD_BIT);
 sbi(CAM_DATA_PORT, CAM_START_BIT);
 camStepDelay();

 camClockH();
 camStepDelay();
 cbi(CAM_DATA_PORT, CAM_START_BIT);
 camStepDelay();
}

// Sends a blank 'xck' pulse to the AR chip.
void camClockAR()
{
 camClockL();
 camStepDelay();
 camStepDelay();

 camClockH();
 camStepDelay();
 camStepDelay();
}

// Wait read signal from the AR chip
unsigned char camWaitRead()
{
   camClockL();
   camStepDelay();
   camStepDelay();

   camClockH();
   camStepDelay();
   if((inp(CAM_READ_PIN) & (1 << CAM_READ_BIT))) {
     camStepDelay();
	 return TRUE;
   } else {
     camStepDelay();
	 return FALSE;
   }
}

// Read pixels from AR until READ signal is unraise
unsigned char camReadPixels()
{
	camClockL();
    camStepDelay();
    camStepDelay();
	
	camClockH();
	camStepDelay();
	camReadPixelDone=FALSE;
    adcStart();
    if(!(inp(CAM_READ_IN) & (1 << CAM_READ_BIT))) {
       camStepDelay(); // end of read sequence
	   return TRUE;
    } else {
      while(!camReadPixelDone) {__asm__ __volatile__ ("nop");}
	  return FALSE;
   }
}

//############################################################################
//#### PRIVATE FUNCTIONS : Pixel treatment                                ####
//############################################################################
// callback run when the ADC conversion is finished = read 1 pixel done
void camReadPixel()
{
	switch(camMode) {
	case CAM_MODE_STANDARD:
		uartWrite(adcGetValue(CAM_ADC_PIN) | 0x01); // never send 0x00 which is the ending signal
		break;
	case CAM_MODE_NO_PIC:
		break;
	case CAM_MODE_ONE_BIT:
		// not supported yet
	case CAM_MODE_TWO_PIX:
		// not supported yet
	case CAM_MODE_ONE_OVER_FOUR:
		// not supported yet
	default:
		uartWrite(adcGetValue(CAM_ADC_PIN) | 0x01);
		break;
	}
		
	camReadPixelDone=TRUE;
}

//############################################################################
//#### PUBLIC FUNCTIONS                                                   ####
//############################################################################
// Initialise the IO ports for the camera
void camInit()
{
	outp(0xFF, CAM_DATA_DDR);      // if you change connections, do not forget to 
	outp(0x40, CAM_LED_READ_DDR);  // change these 2 values
	cbi(CAM_DATA_PORT, CAM_CLOCK_BIT);
	cbi(CAM_DATA_PORT, CAM_RESET_BIT);
	cbi(CAM_DATA_PORT, CAM_LOAD_BIT);
	cbi(CAM_DATA_PORT, CAM_START_BIT);
	cbi(CAM_DATA_PORT, CAM_SIN_BIT);

	cbi(CAM_LED_PORT, CAM_LED_BIT);
}

// locally set the value of a register but do not set it in the AR chip. You 
// must run camSendRegisters1 to write the register value in the chip
void camSetReg1(unsigned char reg,
				unsigned char data) 
{
	camReg1[reg] = data;
}

// Define the protocole use to send the image through the serial port
void camSetMode(unsigned char mode) 
{
	camMode = mode;
}
// Change the clock speed to allow taking photo with a smaller or bigger 
// exposure time than the one defined by default
void camSetClockSpeed(unsigned char clockSpeed)
{
   camClockSpeed=clockSpeed;
}

// Define the the minimal value of pixels. Used by som camera modes
void camSetMinPixValue(unsigned char minV) 
{
	camPixMin = minV;
}

// Define the the maximal value of pixels. Used by som camera modes
void camSetMaxPixValue(unsigned char maxV) 
{
	camPixMax = maxV;
}

// Send the 8 register values to the AR chip
void camSendRegisters1()
{
	unsigned char reg;
	camResetAR();
	for(reg=0; reg<8; ++reg) {
		camSetRegAR(reg, camReg1[reg]);
	}
}

// Take a picture, read it and send it trhough the serial port. 
void camReadPicture()
{
    camCompBuf=0;
	camCompI=0;
	adcRegisterTreatmentCB(camReadPixel);
    adcSelectInput(CAM_ADC_PIN);

	uartWrite(CAM_COM_SEND_START);
	camStartAR();
	// wait AR READ signal
	while(!camWaitRead());
	uartWrite(CAM_COM_START_READ);
	sbi(CAM_LED_PORT, CAM_LED_BIT);

	while(!camReadPixels());
	uartWrite(CAM_COM_STOP_READ);
	cbi(CAM_LED_PORT, CAM_LED_BIT);

	camResetAR();
}
