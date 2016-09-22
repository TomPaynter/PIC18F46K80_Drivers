#include <pic18f46k80.h>
#include <xc.h>

/*  Initialises CAN To 1 MBps @ Fosc = 16 MHz
    uses ONLY RXB0 and a single mask/filter combination, which are both set to 0
    Enables Interrupt */
void CAN_Initialise();

/*  Transmits up to 8 bytes as defined by the array, SID and DLC */
void CAN_Transmit(unsigned char *data, unsigned int SID, unsigned char DLC);

/*  Recieve poll function, returns 1 if data is present and places it and the
    DLC into  the respective variables, otherwise it returns 0 */
unsigned char CAN_Receive_POLL(unsigned char *data, unsigned char *DLC);

/*  Changes mask */
void CAN_Change_Mask(unsigned int mask);

/*  Changes Filter */
void CAN_Change_Filter(unsigned int filter);

/*  Interrupt Routine, not intended to be placed in the routing, but is here 
    as example code. It also relies on the following global variables:

    unsigned char CAN_Data[8], CAN_DLC; //CAN Data global variables for interrupt
    unsigned int CAN_SID; 
 
void CAN_Receive_INT(void); */
