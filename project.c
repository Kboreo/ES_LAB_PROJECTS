#include "project.h"
#include <stdio.h>
#include <stdint.h>

#ifdef DEBUG
void
__error__(char *pcFilename, uint32_t ui32Line)
{
}
#endif

void SetupHardware()
{
	UartSetup();
}

int  main(void)
{		
		uint8_t temp;
		char ctemp;
    volatile uint32_t ui32Loop;		
    
    SetupHardware();
		

		UnlockPins();		//Function that unlocks certain pins that are needed.
    setup_IO();
		setup_UART(ctemp);
		pinReadAndWrite(ui32Loop, temp);
}


