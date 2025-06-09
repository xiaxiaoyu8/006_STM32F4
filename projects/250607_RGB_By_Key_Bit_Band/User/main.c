#include "stm32f4xx.h"
#include "LED.h"
#include "key.h"
#include "delay.h"

// �������ĵ�ַ��λ��ת��Ϊ����λ���������еĵ�ַ
#define BITBAND_ADDR(addr, bitnum)	((addr & 0xF0000000) + 0x02000000 + ((addr & 0x000FFFFF) << 5) + (bitnum << 2))
// ��һ����ַ��λ��ת��Ϊһ������ֱ�Ӳ�����32λָ��
#define ALIAS_REG(addr, bitnum)		(*(volatile uint32_t *)(BITBAND_ADDR((uint32_t)addr, bitnum)))
#define PF9_OUT						ALIAS_REG(&GPIOF->ODR, 9)
/*******************************************************************************
* �� �� ��         : main
* ��������		   : ������
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
int main()//STM32F40_41xxx,USE_STDPERIPH_DRIVER
{
	LED_Init();
	
	//Key_Init();
	while(1)
	{
	for(u8 i = 0; i < 1; i++)
	{
// 250529
//		if(Key_scan() == 0)
//			LED_OnlyLight_R();
//		if(Key_scan() == 1)
//			LED_OnlyLight_G();
//		if(Key_scan() == 2)
//			LED_OnlyLight_B();
		
//		if(Key_scan() == 0)
//			LED_OnlyLight_R();
//		else if(Key_scan() == 1)
//			LED_OnlyLight_G();
//		else if(Key_scan() == 2)
//			LED_OnlyLight_B();
		
// 250607
//		if(Key0_Click() == 1)
//			LED_OnlyLight_R();
//		else if(Key1_Click() == 1)
//			LED_OnlyLight_G();
//		else if(Key2_Click() == 1)
//			LED_OnlyLight_B();
//		else if(Key4_Click() == 1)
//		{
//			LED_Light_R();
//			LED_Light_G();
//			LED_Light_B();
//		}
	}
			
	
	PF9_OUT = 1;
	Delay_Ms(3000);
	PF9_OUT = 0;
	Delay_Ms(3000);
	}
}


