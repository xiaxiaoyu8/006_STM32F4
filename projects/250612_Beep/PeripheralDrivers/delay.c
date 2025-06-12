#include "delay.h"

static u8 fac_us =0;//静态存储“每微秒需要计多少次”

void Delay_Init(void)
{
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);	// 选择SysTick的时钟源为AHB总线时钟的1/8
	fac_us = SYSCLK / 8;//计算出 1 微秒要用多少个时钟周期
}

void Delay_Us(u32 delaytime)
{		
	u32 temp;	    	 
	SysTick->LOAD = delaytime * fac_us; // 时间加载	  		 
	SysTick->VAL = 0x00;        // 清空计数器
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk; // 开始倒数 	 
	do
	{
		temp = SysTick->CTRL;
	} while ((temp & 0x01) && !(temp & (1 << 16))); // 等待时间到达   
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk; // 关闭计数器
	SysTick->VAL = 0X00;       // 清空计数器	 
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

