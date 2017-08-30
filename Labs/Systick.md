# Systick Lab

#### Prelab

Read the Systick portion of the TM4C123 data sheet on the Analog to Digital Converter    
Read the Systick portion of the TivaWare Peripheral Driver Library User's Guide 

#### Lab

* Use the Systick and the NVIC to create code in <em>Systick_helper.c</em> and <em>Systick_helper.h</em> that meet the following requirements
* The software must have a global struct that contains a microseconds and milliseconds counter.
* The milliseconds counter must be 64 bit.
* The microseconds counter must be 32 bit.
* The counter must be extremely accurate.
* You must demonstrate the accuracy of the counter.
* Create a function that accepts 2 pointers to a timer struct and measures the time between difference between the events.
* Creata a function that accepts 2 pointers to a timer struct and returns a 1 or 0 depending on a certain amount of time has elapsed.   

 