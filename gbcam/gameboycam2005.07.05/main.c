/**
 * @file       main.c
 * @brief      MAIN for the gameboy camera interface for AT90S4433
 * 
 * @author     Laurent Saint-Marcel (lstmarcel@yahoo.fr)
 * @date       2005/07/05
 */
 
 #include <interrupt.h>

#include "uart.h"
#include "adc.h"
#include "cam.h"
#include "camCom.h"

/* ------------------------------------------------------------------------ */
/* mainInit                                                                 */
/* ------------------------------------------------------------------------ */
/* Initialize all components                                                */
/* ------------------------------------------------------------------------ */
void mainInit()
{
	uartInit(UART_BAUD_RATE_38400);
	adcInit();
	camInit();
	/* enable interrup */
	sei();
}

/* ------------------------------------------------------------------------ */
/* main                                                                     */
/* ------------------------------------------------------------------------ */
/* Program entry point                                                      */
/* ------------------------------------------------------------------------ */
int main(void)
{
	unsigned char data;
	mainInit();

	while(1) {
		data=uartRead(UART_WAIT_RECEIVE);
		switch(data) {
		case CAM_COM_PING:
			uartWrite(CAM_COM_PONG);
			break;
		case CAM_COM_TAKE_PICTURE:
			camSendRegisters1();
			camReadPicture();
			break;
		case CAM_COM_SET_REGISTERS:
			camSetReg1(0, uartRead(UART_WAIT_RECEIVE));
			camSetReg1(0, uartRead(UART_WAIT_RECEIVE));
			camSetReg1(2, uartRead(UART_WAIT_RECEIVE));
			camSetReg1(3, uartRead(UART_WAIT_RECEIVE));
			camSetReg1(4, uartRead(UART_WAIT_RECEIVE));
			camSetReg1(5, uartRead(UART_WAIT_RECEIVE));
			camSetReg1(6, uartRead(UART_WAIT_RECEIVE));
			camSetReg1(7, uartRead(UART_WAIT_RECEIVE));
			break;
		case CAM_COM_SET_MODE:
			camSetMode(uartRead(UART_WAIT_RECEIVE));
			break;
		case CAM_COM_SET_MIN_MAX:
			camSetMinPixValue(uartRead(UART_WAIT_RECEIVE));
			camSetMaxPixValue(uartRead(UART_WAIT_RECEIVE));
			break;
		case CAM_COM_SET_CLOCK_SPEED:
			camSetClockSpeed(uartRead(UART_WAIT_RECEIVE));
			break;
		default:
			break;
		}
	}
	return 0;
}
