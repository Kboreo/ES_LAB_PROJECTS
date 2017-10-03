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
				printf("no idea\n\n");
				break;			
							
			case '3':
				
				//Uart
				setup_UART(ctemp);
				break;
			
			case '4':
				
				//systick
				printf("Blue LED will stay on for 5 seconds?\n\n");		
				SysTickWait10msDN(100);
				break;
			
			case'5':
				
				//NVIC
				printf ("No idea\n\n");
				break;
			
			case'6':
				
				//ADC
				ADCReadChan();
				break;
			
			default:				
				printf("Ya done messed up, try again!\n\n");
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0x0);  // Turn off LED
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0x0);  // Turn off LED
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0x0);  // Turn off LED
				break;		
		}
	}	
}


