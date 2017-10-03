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
	UnlockPins();
	UartSetup();
	setup_IO();		//UnlockPins();		//Function that unlocks certain pins that are needed.
	SetupSystickDN();
	SetupADC();
	
}

int  main(void)
{		
	SetupHardware();

	char ctemp;
	uint8_t temp;
	volatile uint32_t ui32Loop;	
while (1)
{
	printf("What function would you like to test?\n 1.GPIO\n 2.PWM\n 3.UART\n 4.Systick\n 5.NVIC\n 6.ADC\n");
		ctemp = getc(stdin);
		printf("You entered %c\n\n",ctemp);
		
	switch (ctemp)
			{
			case '1':
				
				//GPIO				
				pinReadAndWrite(ui32Loop, temp); 
				break;	
			
			case '2':
				
				//PWM
				break;			
							
			case '3':
				
				//Uart
			setup_UART(ctemp);
				break;
			
			default:				
				printf("Ya done messed up, try again!\n\n");
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0x0);  // Turn off LED
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0x0);  // Turn off LED
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0x0);  // Turn off LED
				break;		
		}
	}
	
	//uint8_t temp;
		//char ctemp;
  //volatile uint32_t ui32Loop;		
 // pinReadAndWrite(ui32Loop, temp); 
   
		
	
	
	
	//UnlockPins();		//Function that unlocks certain pins that are needed.
    
		//setup_UART(ctemp);
		
	//GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0xF);  // Turn on blue LED
	
//	SysTickWait10msDN(100);
	//SysTickWait10ms(
	
	//GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0xF);  // Turn on blue LED
	
	ADCReadChan();
	
}


