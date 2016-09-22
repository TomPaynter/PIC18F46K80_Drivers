void uart1Initialisation(void);
/* Initialises the EUSART1 buffer to Asynchronous 9600 baud rate, assuming
 * a 16 MHz Fosc*/

void uart1TransmitByte(unsigned char data);
/* Transmits the selected byte. It WILL hang if the buffer is not empty when it
 * starts*/

unsigned char uart1RecieveByte_POLL(unsigned char *data);
/* Returns a 0 if there is no data in the buffer,
 * Returns 1 if there is valid data and then places that in the pointer,
 * Returns 2 if there is corrupted data and discards it.*/

/* UART2 Libraries */
 void uart2Initialisation(void);
 void uart2TransmitByte(unsigned char data);
 unsigned char uart2RecieveByte_POLL(unsigned char *data);
