#ifndef _led_H
    #define _led_H

    #include "system.h"

    #define LED1_PORT 			GPIOC   
    #define LED1_PIN 			GPIO_Pin_13
    #define LED1_PORT_RCC		RCC_AHB1Periph_GPIOC

    #define LED2_PORT 			GPIOF   
    #define LED2_PIN 			GPIO_Pin_10
    #define LED2_PORT_RCC		RCC_AHB1Periph_GPIOF


    void LED_Init(void);
    void LED_Set(char id ,bool mode); // id ȡֵ 9, 10

#endif
