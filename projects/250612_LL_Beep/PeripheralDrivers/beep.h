#ifndef __BEEP_H
	#define __BEEP_H
	#include "stm32f4xx.h"
	
	typedef unsigned char				u8;
	typedef unsigned short int		    u16;
	typedef unsigned int                u32;
	typedef unsigned long int      		u64;
	
	#define BEEP_PORT_RCC	RCC_AHB1Periph_GPIOF
	#define BEEP_PORT		GPIOF
	#define BEEP_Pin		GPIO_Pin_8
	
	#define BEEP		PFout(8)
	
	void Beep_Init(void);
	void Beep_loud(u32 freq);//无源蜂鸣器能输出1.5k - 5kHz的声波
	
	
#endif
