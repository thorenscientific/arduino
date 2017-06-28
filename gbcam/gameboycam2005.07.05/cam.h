/**
 * @file       cam.c
 * @brief      gameboy camera interface for AT90S4433
 * 
 * @author     Laurent Saint-Marcel (lstmarcel@yahoo.fr)
 * @date       2005/07/05
 */

#ifndef __CAM_H__
#define __CAM_H__

/**
 * @brief Initialise the IO ports for the camera
 */
void camInit();

/**
 * locally set the value of a register but do not set it in the AR chip. You 
 * must run camSendRegisters1 to write the register value in the chip
 */
void camSetReg1(unsigned char reg,
				unsigned char data);

/**
 * @brief Define the protocole use to send the image through the serial port
 */
void camSetMode(unsigned char mode);

/**
 * @brief Change the clock speed to allow taking photo with a smaller or bigger 
 * exposure time than the one defined by default. Default is 0x0A = clock period = 5us 
 */
void camSetClockSpeed(unsigned char clockSpeed);

/**
 * @brief Define the the minimal value of pixels. Used by som camera modes
 */
void camSetMinPixValue(unsigned char minV);

/**
 * @brief Define the the maximal value of pixels. Used by som camera modes
 */
void camSetMaxPixValue(unsigned char maxV); 

/**
 * @brief Send the 8 register values to the AR chip
 */
void camSendRegisters1();

/**
 * @brief Take a picture, read it and send it trhough the serial port. 
 */
void camReadPicture();



#endif
