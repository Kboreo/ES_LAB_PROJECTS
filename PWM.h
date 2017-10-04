
#include <inttypes.h>
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/timer.h"
#include "driverlib/interrupt.h"
#include "driverlib/FPU.h"



int Clock;
int PWMcounter = 0,PWMcounterOV,PWMduty = 0;
float low_State;
float high_State;
float period;
float clockPeriod;
unsigned int high_Ticknum;
unsigned int low_Ticknum;
void Timer0IntHandler_1(void);
void Timer0IntHandler(void);
void Timer0Conf(void);
void PWMConf(unsigned int freq,unsigned int duty_Cycle);

/*
		Timer0 interrupt handler
		interrupt handler for low timing of the PWM signal
*/

void Timer0IntHandler(void){
	
	TimerIntClear(TIMER0_BASE,INT_TIMER0A);																								// Clear the interrupt flag
	GPIOPinWrite(GPIO_PORTF_BASE,(GPIO_PIN_1),(GPIO_PIN_1));															// Write to pin	
	IntMasterDisable();
	TimerLoadSet(TIMER0_BASE, TIMER_A, high_Ticknum);	
	TimerIntRegister(TIMER0_BASE,TIMER_A,Timer0IntHandler_1);		                         //assign timer0 interurpt to Timer0IntHandler_1 for low timing
	TimerEnable(TIMER0_BASE, TIMER_A);	
	IntMasterEnable();	
	PWMcounter++;                    //increase PWMcounter by 1
	
	if(PWMcounter >= PWMcounterOV){	 //if PWMcounter exceeds PWMcounterOV then increase duty cycle,and if the duty cycle is at max. reset duty cycle to 0
		
		if(PWMduty<100){	
			PWMduty = PWMduty + 5;
			PWMConf(100,PWMduty);
			PWMcounter = 0;
			}
		
		if(PWMduty>=100){
			PWMduty = 0;
			PWMConf(100,PWMduty);
			PWMcounter = 0;
			}
	}
}

/*
		Timer0 interrupt handler
		interrupt handler for low timing of the PWM signal
*/
void Timer0IntHandler_1(void){

  TimerIntClear(TIMER0_BASE,INT_TIMER0A);																							// Clear the interrupt flag
	GPIOPinWrite(GPIO_PORTF_BASE,(GPIO_PIN_1),~(GPIO_PIN_1));														// Write to pin
	IntMasterDisable();
	TimerLoadSet(TIMER0_BASE, TIMER_A, low_Ticknum);
	TimerIntRegister(TIMER0_BASE,TIMER_A,Timer0IntHandler);															//assign timer0 interurpt to Timer0IntHandler for high timing	
	TimerEnable(TIMER0_BASE, TIMER_A);
	IntMasterEnable();
	
}