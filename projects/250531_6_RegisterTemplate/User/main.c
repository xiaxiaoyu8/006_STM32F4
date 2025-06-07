#include "stm32f4xx.h"

typedef unsigned int u32;   //类型重定义 unsigned int -- u32


/*******************************************************************************
自定义适配宏定义
*******************************************************************************/

#define CPU_FREQ_MHZ 168 //F407主频168MHz


// 计算循环次数（软件延时，每次循环大约耗 4 个周期）
/*******************************************************************************
* 函 数 名         : delay
* 函数功能		   : 延时函数，通过while循环占用CPU，达到延时功能
* 输    入         : i
* 输    出         : 无
*******************************************************************************/
// 毫秒延时函数
void delay_ms(u32 delaytime)
{
    u32 i, j;
    for(i = 0; i < delaytime; i++)
    {
        for(j = 0; j < CPU_FREQ_MHZ * 1000 / 4 / 14; j++) // 168MHz下大约1ms
        {
        }
    }
}

// 微秒延时函数
void delay_us(u32 delaytime)
{
    u32 i, j;
    for(i = 0; i < delaytime; i++)
    {
        for(j = 0; j < CPU_FREQ_MHZ / 4 / 14 * 4 /7; j++) // 168MHz下大约1us
        {
        }
    }
}


void SystemInit(void)
{
	
}


void LEDS_TurnOffAll(void)
{
	GPIOF_BSRR = (1<<(9)) | (1<<(10)) | (1<<(11));
}


void LEDS_OnlyLight(int id)//id范围为[0,2]
{
	GPIOF_BSRR=(1<<(16+id +9));
}

void LEDS_R_OnlyLight(void)
{
	GPIOF_BSRR=(1<<(16+9));
}


void LEDS_G_OnlyLight(void)
{
	GPIOF_BSRR=(1<<(16+10));
}


void LEDS_B_OnlyLight(void)
{
	GPIOF_BSRR=(1<<(16+11));
}

/*******************************************************************************
* 函 数 名         : main
* 函数功能		   : 主函数
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
int main()
{
	
	/*
	F9  - R
	F10 - G
	F11 - B
	*/
	RCC_AHB1ENR |= 1<<5;
	GPIOF_MODER = (1<<(2*9)) | (1<<(2*10)) | (1<<(2*11));
	
	LEDS_TurnOffAll();
	int i;
	while(1)
	{
		for(i=0;i<3;i++)
		{
			LEDS_OnlyLight(i);
			delay_us(5000000);
			LEDS_TurnOffAll();
		}
	}
}





