#ifndef __DELAY_H
	#define __DELAY_H
	#include "misc.h"
	typedef unsigned long int	u64;
	typedef unsigned int		u32;
	typedef unsigned short int	u16;
	typedef unsigned char		u8;
	/*******************************************************************************
	自定义适配宏定义
	*******************************************************************************/

	#define SYSCLK 168 //F407主频168MHz
	
	void Delay_Init(void); // 声明：这个函数叫Delay_Init，返回void，不带任何参数。
	void Delay_S(u32 delaytime);
	void Delay_Ms(u32 delaytime);
	void Delay_Us(u32 delaytime);
	
#endif
