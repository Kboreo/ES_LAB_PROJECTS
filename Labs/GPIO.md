# GPIO Skill Development

#### Prelab

Read the GPIO portion of the TM4C123 data sheet on the Analog to Digital Converter    
Read the GPIO portion of the TivaWare Peripheral Driver Library User's Guide   

#### Lab

Connect at minimum 2 momentary switches, 2 toggles switches and 4 LEDs to your board.

Create a C file called Gpio_helper.c and a header file called Gpio_helper.h and add them to your project in the appropriate folders. 

In Gpio_helper.h create a three function prototypes as shown below
```C    
	void Gpio_setup (void) ; 
	void process_GPIO( void );
	void print_GPIO_DATA( void );
```     
In the Gpio_helper.c file include the header file and template of the function.  It should look like this
```C    
	#include "Gpio_helper.h"

	//This function sets up GPIO pins
	void Gpio_setup()
	{
		//code here.
	} 

	//This function retrieves the GPIO data
	void process_GPIO();
	{
		//code here.
	} 

	//This function prints the GPIO_DATA  
	//in a human readable format to the terminal
	void print_GPIO_data();
	{
		//Uart must be initialized first.
		//code here.
	} 
```

In the Gpio_setup function.  Initialize your gpio.  You can look at example projects to figure it out.  This well help you with code reading skills. 

In your main.c create a function called "LED display".  Create some behavior that uses the buttons to control the LEDs and make sure to describe it in the comments.
  
In your writeup at the top of the c file, make sure to describe in detail how the peripheral is setup, pin configuration, and sensors used. Discuss the issues in code, changes that might need to be made, etc.  Comment on possible other hardware configurations.  

Save your code, commmit it, push to github when documented.  