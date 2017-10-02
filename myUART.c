#include <stdio.h>
#include <stdint.h>
#include "myUART.h"

void setup_UART(char ctemp)
{
	printf("What LED would you like to turn on?\n1.Blue\n2.Red\n3.Green\n");
		ctemp = getc(stdin);
		printf("%c",ctemp);
		
	switch (ctemp)
			{
			case '1':
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0xF);  // Turn on Blue LED				
				break;			
			case '2':
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0xF);  // Turn on Red LED				
				break;			
			case '3':
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0xF);  // Turn on Green LED
				break;			
			default:				
				printf("Ya done messed up, try again!");
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0x0);  // Turn off Red LED
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0x0);  // Turn off Green LED
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0x0);  // Turn off Blue LED
				break;		
		}
	
}