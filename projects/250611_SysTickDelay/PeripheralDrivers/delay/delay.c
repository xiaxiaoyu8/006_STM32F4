#include "delay.h"

static u8 fac_us =0;

void Delay_Init(void)
{
	// ѡ��SysTick��ʱ��ԴΪAHB����ʱ�ӵ�1/8
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);	
	fac_us = SYSCLK / 8;	

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

void Delay_Ms(u16 delaytime)
{
	u16 i;
	for(i = 0; i < delaytime;i++)
	{
		Delay_Us(1000); // ѭ������1000us����ʱ
	}
}
void Delay_S(u8 delaytime)
{
	u16 i;
	for(i = 0; i < delaytime;i++)
	{
		Delay_Ms(1000); // ѭ������1000us����ʱ
	}
}
