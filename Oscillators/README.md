# Internal Oscillators

When using the internal oscillator, as defined in the configuration word. It is possible to uncrease the clock frequency to 16 MHz. This is acheived by the OSCCON registers.

```c
OSCCONbits.IRCF = 0b111; //16 MHz Internal Clock
```
