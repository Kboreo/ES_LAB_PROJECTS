/*********************************************************************************************************************************
**
** Module Name:   project.c
**
** Module Description: C file 
**
**********************************************************************************************************************************
**
** Author(s):		Kodey Boreo, Phillip Tesolin 
**
**********************************************************************************************************************************/

//Includes
#include "project.h"
#include <stdio.h>
#include <stdint.h>

#ifdef DEBUG

void
__error__(char *pcFilename, uint32_t ui32Line)
{
}
#endif

//Function Protoypes

void SetupHardware()  //Function that sets up all of the pins,ports, etc... that are used in the program
{
	UnlockPins();	//Unlocks pins that are used so they can be inputs or outputs
	UartSetup();	//Sets up Uart communication using RealTerm
	setup_IO();		//UnlockPins();		//Function that unlocks certain pins that are needed.
	SetupSystickDN();	//Sets up the timers and hardware to use systick
	SetupADC();	//Hardware setup for ADC 
}

//Main Code
int  main(void)
{		
	//Variables
	char ctemp; //Temp char used for UART
	uint8_t temp;	//Temp 8-bit int used for gpio functions
	volatile uint32_t ui32Loop; //32-bit int used for multiple functions 
	
	SetupHardware();
	
//While loop for main user menu	
while (1)
{
		printf("What function would you like to test?\n 1.GPIO\n 2.PWM\n 3.UART\n 4.Systick\n 5.NVIC\n 6.ADC\n"); //Askes user what function they would like to use.
		ctemp = getc(stdin); //Gets a char from the terminal from the user.
		printf("You entered %c\n\n",ctemp); //Lets the user know what they have selected
		
		switch (ctemp)		//Switch statement that selects which function depending on the user input.
		{
			//GPIO
			case '1':						
				pinReadAndWrite(ui32Loop, temp); 
				break;	
			
			//PWM
			case '2':								
				pwmTest();
				break;
			
			//Uart				
			case '3':
				setup_UART(ctemp);
				break;
			
			//systick
			case '4':				
				printf("Blue LED will stay on for 5 seconds?\n\n");		
				SysTickWait10msDN(100);
				break;
			
			//NVIC
			case'5':				
				printf ("No idea\n\n");
				break;
			
			//ADC
			case'6':				
				ADCReadChan();
				break;
			
			//Default case if user types anything other than the given options
			default:				
				printf("Ya done messed up, try again!\n\n");
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0x0);  // Turn off LED
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0x0);  // Turn off LED
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0x0);  // Turn off LED
				break;		
		}
	}	
}


