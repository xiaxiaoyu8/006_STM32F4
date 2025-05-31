#include "stm32f4xx.h"

typedef unsigned int u32;   //类型重定义 unsigned int -- u32

void SystemInit(void)
{
	
}

/*******************************************************************************
* 函 数 名         : delay
* 函数功能		   : 延时函数，通过while循环占用CPU，达到延时功能
* 输    入         : i
* 输    出         : 无
*******************************************************************************/
void delay(u32 i)
{
	while(i--);
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
	delay(0xFFFFF);
	delay(0xFFFFF);
	delay(0xFFFFF);
	delay(0xFFFFF);
	delay(0xFFFFF);
	delay(0xFFFFF);
	int i;
	while(1)
	{
		for(i=0;i<3;i++)
		{
			LEDS_OnlyLight(i);
			delay(0xFFFFFF);
			LEDS_TurnOffAll();
		}
	}
}





