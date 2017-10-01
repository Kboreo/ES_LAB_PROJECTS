#include "Systick_helper.h"


#define NVIC_ST_CTRL_R          (*((volatile unsigned long *)0xE000E010))
#define NVIC_ST_RELOAD_R        (*((volatile unsigned long *)0xE000E014))
#define NVIC_ST_CURRENT_R       (*((volatile unsigned long *)0xE000E018))
#define NVIC_ST_CTRL_COUNT      0x00010000  // Count flag
#define NVIC_ST_CTRL_CLK_SRC    0x00000004  // Clock Source
#define NVIC_ST_CTRL_INTEN      0x00000002  // Interrupt enable
#define NVIC_ST_CTRL_ENABLE     0x00000001  // Counter mode
#define NVIC_ST_RELOAD_M        0x00FFFFFF  // Counter load value

void SetupSystick()
{
	NVIC_ST_CTRL_R = 0; // disable SysTick during setup
	NVIC_ST_RELOAD_R = NVIC_ST_RELOAD_M; // maximum reload value
	NVIC_ST_CURRENT_R = 0; // any write to current clears it
	NVIC_ST_CTRL_R = NVIC_ST_CTRL_ENABLE+NVIC_ST_CTRL_CLK_SRC; // enable SysTick with core clock

}


// Time delay using busy wait.
// The delay parameter is in units of the 80 MHz core clock. (12.5 ns)
void SysTickWait(unsigned long delay)
{
	NVIC_ST_RELOAD_R = delay-1; // number of counts to wait
	NVIC_ST_CURRENT_R = 0; // any value written to CURRENT clears
	while((NVIC_ST_CTRL_R&0x00010000)==0)
	{
			// wait for count flag
	}
}

// 800000*12.5ns equals 10ms
void SysTickWait10ms(unsigned long delay)
{
	unsigned long i;
	for(i=0; i<delay; i++);		// wait 10ms
	SysTickWait(800000);
}






