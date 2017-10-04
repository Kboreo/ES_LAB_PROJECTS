/*********************************************************************************************************************************
**
** Module Name:   LED.c
**
** Module Description: Header file for the variables and functions unsed for project.
**
**********************************************************************************************************************************
**
** Author(s):		Kodey Boreo,
** Creation Date:   11-Sep-2017
**
**********************************************************************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include "LED.h"

void UnlockPins(char c)
{	
	switch (c)
	{
		case 'f':					
			//Need to Unlock PF4
			HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
			HWREG(GPIO_PORTF_BASE + GPIO_O_CR) = 0xFF;
			HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = 0; 
			break;		
//		case'e':
//			break;
		default:
			break;	
	}
	
}