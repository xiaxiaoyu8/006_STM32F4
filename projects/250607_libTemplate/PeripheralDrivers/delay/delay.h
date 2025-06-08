#ifndef __DELAY_H
	#define __DELAY_H
	typedef unsigned int u32;
	/*******************************************************************************
	自定义适配宏定义
	*******************************************************************************/

	#define CPU_FREQ_MHZ 168 //F407主频168MHz

	void Delay_Ms(u32 delaytime);
	void Delay_Us(u32 delaytime);
		
	
#endif
