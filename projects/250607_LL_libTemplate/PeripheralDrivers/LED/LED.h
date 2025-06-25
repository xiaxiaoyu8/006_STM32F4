#ifndef __LED_H
	#define __LED_H	
	#include "stm32f4xx.h"
	
	#define RGB_PORT_RCC	RCC_AHB1Periph_GPIOF
	#define RGB_PORT		GPIOF
	#define Pin_R			GPIO_Pin_9
	#define Pin_G			GPIO_Pin_10
	#define Pin_B			GPIO_Pin_11
	
	void LED_Init(void);
	void LED_TurnOn5S(void);
	void LED_TurnOff5S(void);
	
	
#endif
