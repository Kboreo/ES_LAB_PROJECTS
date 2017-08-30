# ADC Skill Development

#### Prelab

Read the Analog to Digital Converter portion of the TM4C123 data sheet on the Analog to Digital Converter    
Read the Analog to Digital Converter portion of the TivaWare Peripheral Driver Library User's Guide

#### Lab

Connect at minimum 2 slide pots, 2 regular pots 2 analog sensors to your board.

Create a C file called ADC_helper.c and a header file called ADC_helper.h

In ADC_helper.h create struct that defines all the ADC data you will be reading in and call it ADC_DATA

	struct ADC_DATA 
	{
		...variables
	}; 

In ADC_helper.h create three function prototypes, and make sure you understand what the second and third function prototype are doing before you proceed.
```C    
	void ADC_setup (void) ; 
	void process_ADC( struct ADC_DATA * );
	void print_ADC_DATA( struct ADC_DATA * );
``` 
In the ADC_helper.c file include the header file and create a function template. 

```C    
	#include "ADC_helper.h"

	//This function will setup your ADC hardware as you see fit.
	void ADC_setup()
	{
		//code here.
	} 

	//This function retrieves the ADC data and 
	//stores it in the struct
	void process_ADC( struct ADC_DATA * data_ptr);
	{
		//code here.
	} 

	//This function prints the ADC_DATA struct 
	//in a human readable format to the terminal
	void print_ADC_data( struct ADC_DATA * data_ptr);
	{
		//Uart must be initialized first.
		//code here.
	} 
```


Add the files to the your project appropriately and make sure it compiles.  

In the ADC_setup function, initialize and setup your ADC lines.  Consult the data sheet sections and peripheral driver library you read as a prelab in order to help you.   

* Read in the ADC values and print them to the screen in Volts and Hexadecimal values.  
* Check your accuracy with a voltmeter or oscilliscope. Make note of the error in your documentation.  
* Print the value of the sensor to the screen as well, not the voltage. 
	*  Ie.  If it is a presure sensor and you are putting 1N of force on it, make sure it displays 1N of force.  

In your writeup at the top of the c file, make sure to describe in detail how the peripheral is setup, pin configuration, and sensors used. Discuss the issues in code, changes that might need to be made, etc.  Comment on possible other hardware configurations.  

Save your code, commmit it, push to github when documented.  
