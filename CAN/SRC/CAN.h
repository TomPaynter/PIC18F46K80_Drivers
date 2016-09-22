#include <pic18f46k80.h>
#include <xc.h>

void CAN_Initialise();

void CAN_Transmit(unsigned char *data, unsigned int SID, unsigned char DLC);

unsigned char CAN_Receive(unsigned char *data, unsigned char *DLC);

void CAN_Change_Mask(unsigned int mask);

void CAN_Change_Filter(unsigned int filter);