#include "stm32f4xx.h"
#include "system.h"
#include "LED.h"
#include "key.h"
#include "delay.h"
#include "beep.h"


/*******************************************************************************
* 函 数 名         : main
* 函数功能		   : 主函数
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
int main()//STM32F40_41xxx,USE_STDPERIPH_DRIVER
{
	LED_Init();
	Key_Init();
	Delay_Init();
	Beep_Init();
	u32 freq = 1500;
	while(1)
	{
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
		
		if(Key0_Click() == 1)
		{
			freq+=100;
			LED_OnlyLight_R();
		}
		else if(Key1_Click() == 1)
			LED_OnlyLight_G();
		else if(Key2_Click() == 1)
			LED_OnlyLight_B();
		else if(Key4_Click() == 1)
		{
			LED_Light_R();
			LED_Light_G();
			LED_Light_B();
			BEEP = !BEEP;
		}
		
			
	}
}


