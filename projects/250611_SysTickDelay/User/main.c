#include "stm32f4xx.h"
#include "LED.h"
#include "key.h"
#include "delay.h"


/*******************************************************************************
* 函 数 名         : main
* 函数功能		   : 主函数
* 输    入         : 无
* 输    出         : 无
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


