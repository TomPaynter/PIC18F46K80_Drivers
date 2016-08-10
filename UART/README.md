#Asynchronous UART

##Initialisation

For EUSART1 to be used the following must occur:
- SPEN(RCSTA1<7>)must be set (=1)
- For Asynchronous and Synchronous Master modes, TRISx<x> must be cleared (= 0)
- For Synchronous Slavemode, TRISx<x> must be set (= 1)

###For Asynchronous Operation of EUSART1:

```c
RCSTA1bits.SPEN = 1;
TRISBITS.TRISC6 = 0;
TRISbits.TRISC7 = 0;
```

![TXTAx](https://github.com/TomPaynter/PIC18F46K80_Drivers/blob/master/UART/TXTAx.png)

8 Bit transmission mode.
Transmit enables
Asynchronous mode
*high speed or low speed

```c
TXTA1 = 0b00100*000;
```

![RCSTAx](https://github.com/TomPaynter/PIC18F46K80_Drivers/blob/master/UART/RCSTAx.png)

Enable serial port.
8 Bit reception
Enable reciever

```c
RCSTA1 = 0b10010000;
```

![BAUDCONx](https://github.com/TomPaynter/PIC18F46K80_Drivers/blob/master/UART/BAUDCONx.png)
Non-inverted logic levels
Lines idle high.
*i think we want 8 bitbaud

```c
BAUDCON1 = 0b0000*000;
```
