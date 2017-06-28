/**
 * @file       camCom.h
 * @brief      Communication protocol for the gameboy camera
 * 
 * @author     Laurent Saint-Marcel (lstmarcel@yahoo.fr)
 * @date       2005/05/5
 */
 
#ifndef __CAM_COM_H__
#define __CAM_COM_H__

// orders from PC -> ATMEL
#define CAM_COM_PING            0x01
#define CAM_COM_SET_REGISTERS   0x02
#define CAM_COM_TAKE_PICTURE    0x03
#define CAM_COM_SET_MODE        0x04
#define CAM_COM_SET_MIN_MAX     0x05
#define CAM_COM_SET_CLOCK_SPEED 0x06

// answers from ATMEL -> PC
#define CAM_COM_PONG       0x01
#define CAM_COM_SEND_START 0x02
#define CAM_COM_START_READ 0x03
#define CAM_COM_STOP_READ  0x00

// modes of the camera
#define CAM_MODE_STANDARD       0x20 // send one byte per pixel = 128*128 bytes data = [0x01:0xFF]
#define CAM_MODE_NO_PIC         0x21 // do not send the picture
#define CAM_MODE_ONE_BIT        0x22 // send a black&white picture, every pixel is sent one 1 bit
#define CAM_MODE_TWO_PIX        0x23 // one pix=4 bytes
#define CAM_MODE_ONE_OVER_FOUR  0x24 // send one pixel over 4 => image size = 64*64

#endif
