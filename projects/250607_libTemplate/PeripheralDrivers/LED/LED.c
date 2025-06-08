#include "LED.h"
#include "delay.h"


void LED_Init(void)
{
	GPIO_InitTypeDef ZYH_GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd(RGB_PORT_RCC, ENABLE);//ʹ��GPIOF�˿�ʱ��
	ZYH_GPIO_InitStructure.GPIO_Pin = Pin_R | Pin_G | Pin_B;	
	ZYH_GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	ZYH_GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	ZYH_GPIO_InitStructure.GPIO_Speed = GPIO_Low_Speed;
	GPIO_Init(GPIOF, &ZYH_GPIO_InitStructure);//GPIOF�����������ַ
	
	GPIO_SetBits(RGB_PORT, Pin_R);//��ʼ������R��ɫ��
	GPIO_SetBits(RGB_PORT, Pin_G);//��ʼ��Ϩ��G��
	GPIO_SetBits(RGB_PORT, Pin_B);//��ʼ��Ϩ��B��
}
void LED_TurnOn5S(void)
{
	GPIO_ResetBits(RGB_PORT, Pin_B);
	Delay_Ms(5000);
	GPIO_SetBits(RGB_PORT, Pin_B);
}
void LED_TurnOff5S(void)
{
	GPIO_SetBits(RGB_PORT, Pin_B);
	Delay_Ms(5000);
	GPIO_ResetBits(RGB_PORT, Pin_B);	
}
