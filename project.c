#include "project.h"
#include <stdio.h>
#include <stdint.h>
#include "HAL_ADC.h"


	


//*****************************************************************************
//
// The error routine that is called if the driver library encounters an error.
//
//*****************************************************************************

#ifdef DEBUG
void
__error__(char *pcFilename, uint32_t ui32Line)
{
}
#endif


void SetupHardware()
{
	UartSetup();
	void SetupADC();
	void SetupADCPins();

}

void UnlockPins()
{
	//Need to Unlock PF4
	HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
	HWREG(GPIO_PORTF_BASE + GPIO_O_CR) = 0xFF;
	HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = 0; 
	
}








int  main(void)
{

	

	//*******************************
		//Setup/unlock pins as inputs and outputs
		
		uint8_t temp;
    volatile uint32_t ui32Loop;
		uint32_t ui32Value;

	// Enable the GPIO port that is used for the on-board LED 
		SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF | SYSCTL_PERIPH_GPIOA);

		// Enable the ADC0 module.
		SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);
    
		SetupHardware();
		

		
		// Check if the peripheral access is enabled.
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF | SYSCTL_PERIPH_GPIOA))
    {   
		}
		
		// Wait for the ADC0 module to be ready.
	while(!SysCtlPeripheralReady(SYSCTL_PERIPH_ADC0))
		{
		}
		
		UnlockPins();
    
		// Enable the GPIO pin for the LED (PF 3, 2, 1).  Set the direction as output, and
    // enable the GPIO pin for digital function.
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_3|GPIO_PIN_2|GPIO_PIN_1); // set Port F pin 1,2,3 as output
		GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE, GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4); // set Port A pin 2,3,4 as output
		GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_4|GPIO_PIN_0); // set PORT F pin 0 and 4 as input
		
		//these two switchs need an internal pull up on pins
		GPIOPadConfigSet(GPIO_PORTF_BASE,GPIO_PIN_0|GPIO_PIN_4,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPU);//set internal pullup R for pin 0 and 4
		
		// set x equal to the value of switch 1
		int x = GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_0);
		 
		//************************************************
		//A to D stuff
		// Configure of the pins for ADC Type
	//GPIOPinTypeADC(GPIO_PORTE_BASE, GPIO_PIN_4);
	//GPIOPinTypeADC(GPIO_PORTE_BASE, GPIO_PIN_5);

//	void SetupADC();
//	void SetupADCPins();
	int usafd = 839;			
		
   	
		
			
			 
		for(uint32_t i=0; i<13;i++)
			{
			ADC_Values[i]=0;
		}
	 ADCReadChan();
		
		for(uint8_t i = 0; i < 13; i++)
		{
			
	printf("ADC Values are %d, \n", ADC_Values[i]);
		}
			
	 while(1)
    {			
	
			
			
			//**************************
			// Flash LED Blue when switch 1 is pressed
			//Reads the value of switch 2 
			x = GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_0);
			
			//Loop will run, blue LED flashes if switch 2 is pressed | == 0
			while(x == 0)
		{
				//Reads the value of switch 2 while in loop
				//Will exit loop when switch is released 
				x = GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_0);	
		
				
        // Turn on the LED.
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0xFF);


        // Delay for a bit.
        for(ui32Loop = 0; ui32Loop < 200000; ui32Loop++)
        {
        }

        // Turn off the LED.
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0x0);

        // Delay for a bit.
        for(ui32Loop = 0; ui32Loop < 200000; ui32Loop++)
        {
        }
				
    }
		}
		return(0);
}

//******************
//A to D stuff

