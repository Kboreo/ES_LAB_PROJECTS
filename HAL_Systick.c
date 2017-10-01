#include "HAL_Systick.h"

void SetupSystickDN()
{
  //NVIC_ST_CTRL_R = 0;                   // disable SysTick during setup
  //NVIC_ST_RELOAD_R = NVIC_ST_RELOAD_M;  // maximum reload value
  //NVIC_ST_CURRENT_R = 0;                // any write to current clears it
	
                                        // enable SysTick with core clock
  //NVIC_ST_CTRL_R = NVIC_ST_CTRL_ENABLE+NVIC_ST_CTRL_CLK_SRC;	
	
	SysTickPeriodSet(NVIC_ST_RELOAD_M);
	SysTickEnable();
}


// Time delay using busy wait.
// The delay parameter is in units of the 80 MHz core clock. (12.5 ns)
void SysTickWaitDN(unsigned long delay)
{
	NVIC_ST_RELOAD_R = delay-1;  // number of counts to wait
  NVIC_ST_CURRENT_R = 0;       // any value written to CURRENT clears
  while((NVIC_ST_CTRL_R&0x00010000)==0)
	{ // wait for count flag
	}
}


// 800000*12.5ns equals 10ms

void SysTickWait10msDN(unsigned long delay)
{
  unsigned long i;
  for(i=0; i<delay; i++)
	{
    SysTickWaitDN(800000);  // wait 10ms
  }
}


