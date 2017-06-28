/**
 * @file       uart.c
 * @brief      serial port communication for AVR (AT90S2313, AT90S4433, AT90S8515)
 * 
 * @author     Laurent Saint-Marcel (lstmarcel@yahoo.fr)
 * @date       2004/07/25
 */
#include <io.h>

#include "uart.h"

#ifndef UCSRB
#define UCSRB UCR
#define UCSRA USR
#endif

/* ------------------------------------------------------------------------*/
/* uartInit                                                                */
/* ------------------------------------------------------------------------*/
void uartInit(unsigned char baud)
{
	/* set speed */
	outp(baud, UBRR);
	/* enable uart (2 directions: rx and tx) */
	outp((1 << RXEN) | (1 << TXEN), UCSRB);
}

/* ------------------------------------------------------------------------*/
/* uartWrite                                                               */
/* ------------------------------------------------------------------------*/
void uartWrite(unsigned char data)
{
	/* wait for data register do be empty */
	while ( !(inp(UCSRA) & (1<<UDRE)) );
	/* send data */
	outp(data, UDR);
}

/* ------------------------------------------------------------------------*/
/* uartRead                                                                */
/* ------------------------------------------------------------------------*/
unsigned char uartRead(unsigned char blocking)
{
	if (blocking == UART_WAIT_RECEIVE) {
		/* wait for data register to be full */
		while ( !(inp(UCSRA) & (1 << RXC)));
	} else if (!(inp(UCSRA) & (1 << RXC))) {
		/* data register empty, return the error code */
		return UART_NO_RCV;
	}
	/* data register not empty, return the data */
	return inp(UDR);
}
