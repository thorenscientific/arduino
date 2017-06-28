/**
 * @file       uart.h
 * @brief      serial port communication for AVR (AT90S2313, AT90S4433, AT90S8515)
 * 
 * @author     Laurent Saint-Marcel (lstmarcel@yahoo.fr)
 * @date       2004/07/25
 */

#ifndef __UART_H__
#define __UART_H__

/**
 * @brief Byte returned by uartReceive when there is no byte received on serial port
 * @see uartReceive
 */
#define UART_NO_RCV             0x00
/**
 * @brief uartReceive waits for a byte to be received on serial port before returning
 * @see uartReceive
 */
#define UART_WAIT_RECEIVE       0x01
/**
 * @brief uartReceive does not wait for a byte to be received on serial port before returning
 * @see uartReceive
 */
#define UART_DONT_WAIT_RECEIVE  0x00



/*************** Baud rates defined for a 8MHz cristal ***************/
/**
 * @brief Baud rate value 2400, to be used with uartInit
 */
#define UART_BAUD_RATE_2400		207
/**
 * @brief Baud rate value 4800, to be used with uartInit
 */
#define UART_BAUD_RATE_4800		103
/**
 * @brief Baud rate value 9600, to be used with uartInit
 */
#define UART_BAUD_RATE_9600		51
/**
 * @brief Baud rate value 14400, to be used with uartInit
 */
#define UART_BAUD_RATE_14400	34
/**
 * @brief Baud rate value 19200, to be used with uartInit
 */
#define UART_BAUD_RATE_19200	25
/**
 * @brief Baud rate value 38400, to be used with uartInit
 */
#define UART_BAUD_RATE_38400	12


/**
 * @brief This function initialize serial port
 * @param baud rate speed for serial port,
 * @see   BAUD_RATE_9600... 
 */
void uartInit(unsigned char baud);

/**
 * @brief This function sends one byte on serial port
 */
void uartWrite(unsigned char data);

/**
 * @brief This function gets one byte from serial port
 * @param blocking if set to UART_DONT_WAIT_RECEIVE, if there is no byte 
 *        waiting on serial port, the function returns immediatly the value 
 *        UART_NO_RCV\n
 *        If set to UART_WAIT_RECEIVE, the function waits until a byte
 *        arrives on serial port and it returns it
 *        
 * @see UART_WAIT_RECEIVE      
 * @see UART_DONT_WAIT_RECEIVE
 * @see UART_NO_RCV
 */
unsigned char uartRead(unsigned char blocking);

#endif /* __UART_H__ */
