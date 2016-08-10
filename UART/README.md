#Asynchronous UART

##Initialisation

For EUSART1 to be used the following must occur:
- SPEN(RCSTA1<7>)must be set (=1)
- For Asynchronous and Synchronous Master modes, TRISx<x> must be cleared (= 0)
- For Synchronous Slavemode, TRISx<x> must be set (= 1)

For Asynchronous Operation of EUSART1:

```c
RCSTA1bits.SPEN = 1;
TRISBITS.TRISC6 = 0;
TRISbits.TRISC7 = 0;
```


