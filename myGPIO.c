#include <stdio.h>
#include <stdint.h>
#include "myGPIO.h"

#include "tm4c123gh6pm.h"	// Header file accesses registers in TMC123 microcontroller

//define easy to read names for registers
#define GPIO_PORTF_DATA_R       (*((volatile unsigned long *)0x400253FC))
#define GPIO_PORTF_DIR_R        (*((volatile unsigned long *)0x40025400))
#define GPIO_PORTF_AFSEL_R      (*((volatile unsigned long *)0x40025420))
#define GPIO_PORTF_PUR_R        (*((volatile unsigned long *)0x40025510))
#define GPIO_PORTF_DEN_R        (*((volatile unsigned long *)0x4002551C))
#define GPIO_PORTF_LOCK_R       (*((volatile unsigned long *)0x40025520))
#define GPIO_PORTF_CR_R         (*((volatile unsigned long *)0x40025524))
#define GPIO_PORTF_AMSEL_R      (*((volatile unsigned long *)0x40025528))
#define GPIO_PORTF_PCTL_R       (*((volatile unsigned long *)0x4002552C))
#define SYSCTL_RCGC2_R          (*((volatile unsigned long *)0x400FE108))

//   Global Variables
unsigned long SW1, SW2;  	// input from PF0 and PF4

//   Function Prototypes
void PortF_Init(void);		
void Delay(void);

void setup_IO()
{
	// Enable the GPIO port that is used for the on-board LED.
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	// Enable the GPIO pin for the LED (PF3).  Set the direction as output, and
  // enable the GPIO pin for digital function.
  GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_3|GPIO_PIN_2|GPIO_PIN_1); // set pin 3 and 2 as output
	GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_4|GPIO_PIN_0); // set pin 4 and 0 as input
//	GPIOPinTypeGPIOInput(GPIO_PORTE_BASE, GPIO_PIN_3);
	//these two switches need an internal pull up on pins
	GPIOPadConfigSet(GPIO_PORTF_BASE,GPIO_PIN_0|GPIO_PIN_4,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPU);//set internal pullup R for pin 0 and 4
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF))
    {
    
		}	





// 3. Subroutines Section
   
  PortF_Init();        			// Call initialization of port PF0-PF4    
//  for(int i =0; i<1; i++){
//    SW1 = GPIO_PORTF_DATA_R&0x10; 	// read PF4 into SW1
//    SW2 = GPIO_PORTF_DATA_R&0x01; 	// read PF0 into SW2
//    if(SW1 == 0x00){              	// zero means SW1 is pressed
//      GPIO_PORTF_DATA_R = 0x08;   	// LED is green
//     } 
//    else if(SW2 == 0x00){               // 0x10 means SW1 is not pressed
//      GPIO_PORTF_DATA_R = 0x02;  	// LED is red
//     }
//    Delay();				// wait 0.1 sec
//    GPIO_PORTF_DATA_R = 0x04;    	// LED is blue
//    Delay();                     	// wait 0.1 sec
//  }
}

// Subroutine to initialize port F pins for input and output
// PF4 and PF0 are input SW1 and SW2 respectively
// PF3,PF2,PF1 are outputs to the LED
void PortF_Init(void){ 
  volatile unsigned long delay;
  SYSCTL_RCGC2_R |= 0x00000020;     // 1) F clock
  delay = SYSCTL_RCGC2_R;           // reading register adds a delay   
  GPIO_PORTF_LOCK_R = 0x4C4F434B;   // 2) unlock PortF PF0  
  GPIO_PORTF_CR_R = 0x1F;           // allow changes to PF4-0       
  GPIO_PORTF_AMSEL_R = 0x00;        // 3) disable analog function
  GPIO_PORTF_PCTL_R = 0x00000000;   // 4) GPIO clear bit PCTL  
  GPIO_PORTF_DIR_R = 0x0E;          // 5) PF4,PF0 input, PF3,PF2,PF1 output   
  GPIO_PORTF_AFSEL_R = 0x00;        // 6) no alternate function
  GPIO_PORTF_PUR_R = 0x11;          // enable pullup resistors on PF4,PF0       
  GPIO_PORTF_DEN_R = 0x1F;          // 7) enable digital pins PF4-PF0        
}

//void Delay(void){unsigned long volatile time;
 // time = 727240*200/91;  // 0.1sec
 // while(time){
   // time--;
  //}
//}
		


void pinReadAndWrite(uint32_t ui32Loop,uint8_t temp)
{
		int x;  //Int that contains the output of the button SW2
		int y;  //Int that contains the output of the button SW1
		
		x = GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_0); // set x equal to the output of button SW2 
		y = GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_4); // set x equal to the output of button SW1
		
		while(x == 1)  //While loop that keeps checking until x does not equal 1, meaning SW2 was pushed. 
		{
			x = GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_0);	
		}
			
		
    while(1)
    {
			x = GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_0); // set x equal to the output of button SW2
			y = GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_4); // set x equal to the output of button SW1
			
			if (x && y == 0) //if loop that checks if SW1 and SW2 are pressed, if they are both pressed, blue LED will light.
			{
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0xF);  // Turn on blue LED
				
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
			else  //Else green LED will light.
			{
				UARTCharPut(UART0_BASE, temp);
			  temp++;
        // Turn on the LED.
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0xF);

        // Delay for a bit.
        for(ui32Loop = 0; ui32Loop < 200000; ui32Loop++)
        {
        }

        // Turn off the LED.
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0x0);

        // Delay for a bit.
        for(ui32Loop = 0; ui32Loop < 200000; ui32Loop++)
        {
        }
			}
    }
}