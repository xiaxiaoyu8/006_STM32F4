#ifndef __DELAY_H
	#define __DELAY_H
	#include "misc.h"
	typedef unsigned long int	u64;
	typedef unsigned int		u32;
	typedef unsigned short int	u16;
	typedef unsigned char		u8;
	/*******************************************************************************
	�Զ�������궨��
	*******************************************************************************/

	#define SYSCLK 168 //F407��Ƶ168MHz
	
	void Delay_Init(void); // ���������������Delay_Init������void�������κβ�����
	void Delay_S(u32 delaytime);
	void Delay_Ms(u32 delaytime);
	void Delay_Us(u32 delaytime);
	
#endif
