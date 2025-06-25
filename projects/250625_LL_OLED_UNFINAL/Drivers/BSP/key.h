#ifndef __KEY_H
	#define __KEY_H
    #include "main.h"
	//四个按钮的实现
	/*
	Key2 - PE2  02
	Key1 - PE3	01
	Key0 - PE4  00
	WK_up- PA0  04 按下发送高电平,否则为低电平
	*/
	#define KEY_PORT_RCC	RCC_AHB1Periph_GPIOE
	#define KEY_PORT		GPIOE
	#define WEAKUP_PORT_RCC	RCC_AHB1Periph_GPIOA
	#define WEAKUP_PORT		GPIOA
	
	#define Pin_Key0			GPIO_Pin_4
	#define Pin_Key1			GPIO_Pin_3
	#define Pin_Key2			GPIO_Pin_2
	#define Pin_WAKEUPKey		GPIO_Pin_0 //A组
	
	void Key_Init(void);
	bool Key0_Click(void);
	bool Key1_Click(void);
	bool Key2_Click(void);
	bool Key4_Click(void);
	u8 Key_scan(void);//没有按键抬起默认返回255, 四个按键分别对应0, 1, 2, 3
	
#endif
