#include "stm32f4xx.h"
#include "LED.h"
#include "key.h"
#include "delay.h"


/*******************************************************************************
* �� �� ��         : main
* ��������		   : ������
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
int main()//STM32F40_41xxx,USE_STDPERIPH_DRIVER
{
	Delay_Init();
	LED_Init();
	Key_Init();
	
	while(1)
	{
		LED_OnlyLight_R();
		Delay_Ms(5000);
		LED_OnlyLight_G();
		Delay_Ms(5000);

			
	}
}


