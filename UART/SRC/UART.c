#include <pic18f46k80.h>
#include <xc.h>
#include "UART.h"

/*
UART on EUSART1
9600 bps
8 MHz Fosc
*/

void uart1Initialisation(void) {

  //Enabling UART
  RCSTA1bits.SPEN = 1;

  //Setting TRIS to output
  TRISCbits.TRISC6 = 0;
  TRISCbits.TRISC7 = 0;

  //Setting Asynchronous
  TXSTA1 = 0b00100000;
  RCSTA1 = 0b10010000;
  BAUDCON1 = 0b00001000;

  //Setting Baudrate for 9600 @ Fosc = 8 MHz
  //SPBRGH1 = 0;
  //SPBRG1 = 51;

 //Setting Baudrate for 9600 @ Fosc = 16 MHz
  SPBRGH1 = 0;
  SPBRG1 = 103;

  return;
}

void uart1TransmitByte(unsigned char data) {

  //Double check that the buffer is free, if now hang here.
  while(TXSTA1bits.TRMT == 0);

  //Load output buffer
  TXREG1 = data; //This automatically initiates transmission

  return;
}

unsigned char uart1RecieveByte_POLL(unsigned char *data) {
    if(RC1IF == 1) {
        //Check for read corruption
        if(RCSTA1bits.OERR || RCSTA1bits.FERR){
          RCSTA1bits.CREN = 0;
          RCSTA1bits.CREN = 1;

          return 2;
        }

      *data = RCREG1;

      return 1;
    }

    else {
      return 0;
    }
}

void uart2Initialisation(void) {

  //Enabling UART
  RCSTA2bits.SPEN = 1;

  //Setting TRIS to output
  TRISBbits.TRISB6 = 0;
  TRISBbits.TRISB7 = 0;

  //Setting Asynchronous
  TXSTA2 = 0b00100000;
  RCSTA2 = 0b10010000;
  BAUDCON2 = 0b00001000;

  //Setting Baudrate for 9600 @ Fosc = 8 MHz
  //SPBRGH1 = 0;
  //SPBRG1 = 51;

 //Setting Baudrate for 9600 @ Fosc = 16 MHz
  SPBRGH2 = 0;
  SPBRG2 = 103;

  return;
}

void uart2TransmitByte(unsigned char data) {
  //Double check that the buffer is free, if now hang here.
  while(TXSTA2bits.TRMT == 0);

  //Load output buffer
  TXREG2 = data; //This automatically initiates transmission

  return;
}

unsigned char uart2RecieveByte_POLL(unsigned char *data) {
    if(RC2IF == 1) {
        //Check for read corruption
        if(RCSTA2bits.OERR || RCSTA2bits.FERR){
          RCSTA2bits.CREN = 0;
          RCSTA2bits.CREN = 1;

          return 2;
        }

      *data = RCREG2;

      return 1;
    }

    else {
      return 0;
    }
}
