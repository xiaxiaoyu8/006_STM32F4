#include "LED.h"
#include "delay.h"

void LED_TurnOff(void)
{
	GPIO_SetBits(RGB_PORT, Pin_R);//��ʼ��Ϩ��R��
	GPIO_SetBits(RGB_PORT, Pin_G);//��ʼ��Ϩ��G��
	GPIO_SetBits(RGB_PORT, Pin_B);//��ʼ��Ϩ��B��
}
void LED_Init(void)
{
	GPIO_InitTypeDef ZYH_GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd(RGB_PORT_RCC, ENABLE);//ʹ��GPIOF�˿�ʱ��
	ZYH_GPIO_InitStructure.GPIO_Pin = Pin_R | Pin_G | Pin_B;	
	ZYH_GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	ZYH_GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	ZYH_GPIO_InitStructure.GPIO_Speed = GPIO_Low_Speed;
	GPIO_Init(RGB_PORT, &ZYH_GPIO_InitStructure);//GPIOF�����������ַ
	LED_TurnOff();
}


void LED_OnlyLight_R(void)
{
	LED_TurnOff();
	GPIO_ResetBits(RGB_PORT, Pin_R);
}
void LED_OnlyLight_G(void)
{
	LED_TurnOff();
	GPIO_ResetBits(RGB_PORT, Pin_G);
}
void LED_OnlyLight_B(void)
{
	LED_TurnOff();
	GPIO_ResetBits(RGB_PORT, Pin_B);
}
void LED_Light_R(void)
{
	GPIO_ResetBits(RGB_PORT, Pin_R);
}
void LED_Light_G(void)
{
	GPIO_ResetBits(RGB_PORT, Pin_G);
}
void LED_Light_B(void)
{
	GPIO_ResetBits(RGB_PORT, Pin_B);
}
