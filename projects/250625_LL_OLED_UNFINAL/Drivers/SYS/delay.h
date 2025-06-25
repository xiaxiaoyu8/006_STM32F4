#ifndef __DELAY_H
	#define __DELAY_H
	#include "misc.h"
	/*******************************************************************************
	自定义适配宏定义
	*******************************************************************************/

	#define SYSCLK 168 //F407主频168MHz
	
	void Delay_Init(void);
	void Delay_S(u32 delaytime);
	void Delay_Ms(u32 delaytime);
	void Delay_Us(u32 delaytime);
	
#endif
