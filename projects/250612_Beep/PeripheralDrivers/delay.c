#include "delay.h"

static u8 fac_us =0;//��̬�洢��ÿ΢����Ҫ�ƶ��ٴΡ�

void Delay_Init(void)
{
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);	// ѡ��SysTick��ʱ��ԴΪAHB����ʱ�ӵ�1/8
	fac_us = SYSCLK / 8;//����� 1 ΢��Ҫ�ö��ٸ�ʱ������
}

void Delay_Us(u32 delaytime)
{		
	u32 temp;	    	 
	SysTick->LOAD = delaytime * fac_us; // ʱ�����	  		 
	SysTick->VAL = 0x00;        // ��ռ�����
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk; // ��ʼ���� 	 
	do
	{
		temp = SysTick->CTRL;
	} while ((temp & 0x01) && !(temp & (1 << 16))); // �ȴ�ʱ�䵽��   
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk; // �رռ�����
	SysTick->VAL = 0X00;       // ��ռ�����	 
}

void Delay_Ms(u32 delaytime)
{
	while (delaytime--)
	{
		Delay_Us(1000);
	}
}

void Delay_S(u32 delaytime)
{
	while (delaytime--)
	{
		Delay_Ms(1000);
	}
}

