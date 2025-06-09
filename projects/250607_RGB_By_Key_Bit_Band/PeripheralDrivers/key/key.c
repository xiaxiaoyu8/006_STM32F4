#include "key.h"

void Key_Init(void)
{
	GPIO_InitTypeDef ZYH_GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd(KEY_PORT_RCC, ENABLE);//使能端口时钟
	ZYH_GPIO_InitStructure.GPIO_Pin = Pin_Key0 | Pin_Key1 | Pin_Key2;	
	ZYH_GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	ZYH_GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(KEY_PORT, &ZYH_GPIO_InitStructure);
	
	RCC_AHB1PeriphClockCmd(WEAKUP_PORT_RCC, ENABLE);//使能端口时钟
	ZYH_GPIO_InitStructure.GPIO_Pin = Pin_WAKEUPKey;
	ZYH_GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//重复
	ZYH_GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
	GPIO_Init(WEAKUP_PORT, &ZYH_GPIO_InitStructure);
	
}
bool state[4],last_state[4]={1,1,1,0};
u8 Key_scan(void)
{
	u8 i,click=255;
	state[0] = GPIO_ReadInputDataBit(KEY_PORT,Pin_Key0);
	state[1] = GPIO_ReadInputDataBit(KEY_PORT,Pin_Key1);
	state[2] = GPIO_ReadInputDataBit(KEY_PORT,Pin_Key2);
	if(state[0] == 1 && last_state[0] == 0)
	{
		click = 0;
	}
	if(state[1] == 1 && last_state[1] == 0)
	{
		click = 1;
	}
	if(state[2] == 1 && last_state[2] == 0)
	{
		click = 2;
	}
	for(i = 0; i<4; i++)
	{
		last_state[i] = state[i];
	}
	return click;
}

bool Key0_Click(void)
{
	state[0] = GPIO_ReadInputDataBit(KEY_PORT,Pin_Key0);
	if(state[0] == 1 && last_state[0] == 0)
	{
		last_state[0] = state[0];return 1;
	}
	else
	{
		last_state[0] = state[0];return 0;
	}
}
bool Key1_Click(void)
{
	state[1] = GPIO_ReadInputDataBit(KEY_PORT,Pin_Key1);
	if(state[1] == 1 && last_state[1] == 0)
	{
		last_state[1] = state[1];return 1;
	}
	else
	{
		last_state[1] = state[1];return 0;
	}
	
}
bool Key2_Click(void)
{
	state[2] = GPIO_ReadInputDataBit(KEY_PORT,Pin_Key2);
	if(state[2] == 1 && last_state[2] == 0)
	{
		last_state[2] = state[2];return 1;
	}
	else
	{
		last_state[2] = state[2];return 0;
	}
}

bool Key4_Click(void)
{
	state[3] = GPIO_ReadInputDataBit(WEAKUP_PORT,Pin_WAKEUPKey);
	if(state[3] == 0 && last_state[3] == 1)
	{
		last_state[3] = state[3];return 1;
	}
	else
	{
		last_state[3] = state[3];return 0;
	}
	
}
