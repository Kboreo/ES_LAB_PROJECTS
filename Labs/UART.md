# Uart Skill Development 

#### Prelab

Read the UART portion of the TM4C123 data sheet on the Analog to Digital Converter    
Read the UART portion of the TivaWare Peripheral Driver Library User's Guide   

Create a C file called Uart_helper.c and a header file called Uart_helper.h and add them to your project in the appropriate folders. 

In Uart_helper.h create a three function prototypes as shown below
```C    
	void Uart_setup (void) ; 
	void process_Uart( void );
	void print_start_msg( void );
``` 

In the Gpio_helper.c file include the header file and template of the function.  It should look like this

	#include "Gpio_helper.h"

	//This function sets up your Uart hardware
	void Uart_setup()
	{
		//code here.
	} 

	//This function retrieves Uart data
	void process_Uart();
	{
		//code here.
	} 

	//This function prints a menu in human readable format
	void print_menu()
	{
		//Uart must be initialized first.
		//code here.
	} 

Fill in the code.

In your main.c create a function called <em>read_from_terminal()</em>.  Create code that reads in characters from a menu and executes at minimum 4 events based on the user selection.  
  
In your writeup at the top of the c file, make sure to describe in detail how the peripheral is setup, pin configuration, and sensors used. Discuss the issues in code, changes that might need to be made, etc.  Comment on possible other hardware configurations.  

Save your code, commmit it, push to github when documented.  