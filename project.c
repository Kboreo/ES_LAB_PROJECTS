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
	setup_IO();		//UnlockPins();		//Function that unlocks certain pins that are needed.
	SetupSystickDN();
	SetupADC();
}

int  main(void)
{		
		uint8_t temp;
		char ctemp;
    volatile uint32_t ui32Loop;		
    
    SetupHardware();
		//UnlockPins();		//Function that unlocks certain pins that are needed.
    
		//setup_UART(ctemp);
		//pinReadAndWrite(ui32Loop, temp);
	GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0xF);  // Turn on blue LED
	
//	SysTickWait10msDN(100);
	//SysTickWait10ms(
	
	GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0xF);  // Turn on blue LED
	
	ADCReadChan();
	
}


