/*********************************************************************************************************************************
**
** Module Name:   myUART.c
**
** Module Description: Uses UART to ask user for input to affect different leds on board.
**
**********************************************************************************************************************************
**
** Author(s):		Kodey Boreo, Phillip Tesolin 
**
**********************************************************************************************************************************/

//includes
#include <stdio.h>
#include <stdint.h>
#include "myUART.h"

//Main functions
void setup_UART(char ctemp)
{
	int i =1;	//temp i variable used to exit while loop
	while (i==1)
	{
	printf("What LED would you like to turn on?\n1.Blue\n2.Red\n3.Green\nOr press 4 to exit UART\n"); //Ask user what they would like to do
	ctemp = getc(stdin);	//gets value that user has typed into the terminal 
	printf("%c\n\n",ctemp); //prints out what the user typed, back to the user
		
	switch (ctemp)	//switch statement that takes the users input and turns on the desired led
			{
			case '1':
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0x0);  // Turn off red LED				
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0xF);  // Turn on blue LED		
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0x0);  // Turn off green LED
				break;			
			case '2':
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0xF);  // Turn on red LED	
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0x0);  // Turn off blue LED
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0x0);  // Turn off green LED							
				break;			
			case '3':
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0x0);  // Turn off red LED
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0x0);  // Turn off blue LED				
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0xF);  // Turn on green LED
				break;
			case '4':
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0x0);  // Turn off red LED
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0x0);  // Turn off blue LED
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0x0);  // Turn off green LED				
				i = 0;
				break;
			default:				
				printf("Ya done messed up, try again!\n\n");
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0x0);  // Turn off red LED
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0x0);  // Turn off blue LED
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0x0);  // Turn off green LED
				break;		
		}
	
}
	}