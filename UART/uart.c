/*
UART on EUSART1
250 kbps
16 MHz Fosc
*/

void uartInitialisation(void) {

  //Enabling UART
  RCSTA1bits.SPEN = 1;
  TRISBITS.TRISC6 = 0;
  TRISbits.TRISC7 = 0;
  
  //Setting Asynchronous
  TXTA1 = 0b00000000;
  RCSTA1 = 0b10010000;
  BAUDCON1 = 0b00001000;
  
  //Setting Baudrate
  SPBRGH1 = 0;
  SPBRG1 = 3;
}

void uartTransmitByte(uint8_t data) {
  //Double check that the buffer is free, if now hang here.
  while(TXTA1bits.TRMT == 0);

  TXTA1bits.TXEN = 1; //TODO Could put this in initialisation?
  TXREG1 = data; //This automatically initiates transmission
}

int uartRecieveByte(uint8_t $data) {
  if(RC1IF == 1) {
    data = RCREG1;
    return 1;
  }
  
  else {
    return 0;
  }
}
