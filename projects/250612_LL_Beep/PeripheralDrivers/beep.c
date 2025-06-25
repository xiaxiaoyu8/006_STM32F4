#include "beep.h"
#include "delay.h"

void Beep_Init(void)
{
	GPIO_InitTypeDef ZYH_GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd(BEEP_PORT_RCC, ENABLE);//使能GPIOF端口时钟
	ZYH_GPIO_InitStructure.GPIO_Pin = BEEP_Pin;	
	ZYH_GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	ZYH_GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	ZYH_GPIO_InitStructure.GPIO_Speed = GPIO_Low_Speed;
	GPIO_Init(BEEP_PORT, &ZYH_GPIO_InitStructure);//GPIOF代表外设基地址
	GPIO_ResetBits(BEEP_PORT, BEEP_Pin);//初始化置为低电平,不发出声音
}

void Beep_loud(u32 freq)//无源蜂鸣器能输出1.5k - 5kHz的声波
{
	GPIO_SetBits(BEEP_PORT, BEEP_Pin);
	Delay_Us(freq);
}
