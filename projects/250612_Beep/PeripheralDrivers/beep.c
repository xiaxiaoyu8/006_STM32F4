#include "beep.h"
#include "delay.h"

void Beep_Init(void)
{
	GPIO_InitTypeDef ZYH_GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd(BEEP_PORT_RCC, ENABLE);//ʹ��GPIOF�˿�ʱ��
	ZYH_GPIO_InitStructure.GPIO_Pin = BEEP_Pin;	
	ZYH_GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	ZYH_GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	ZYH_GPIO_InitStructure.GPIO_Speed = GPIO_Low_Speed;
	GPIO_Init(BEEP_PORT, &ZYH_GPIO_InitStructure);//GPIOF�����������ַ
	GPIO_ResetBits(BEEP_PORT, BEEP_Pin);//��ʼ����Ϊ�͵�ƽ,����������
}

void Beep_loud(u32 freq)//��Դ�����������1.5k - 5kHz������
{
	GPIO_SetBits(BEEP_PORT, BEEP_Pin);
	Delay_Us(freq);
}
