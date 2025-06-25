#include "key.h"
#include "./SYSTEM/delay.h"

void Key_Init(void)
{
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	
	GPIO_InitTypeDef YuWei_GPIO_InitStructure;
	YuWei_GPIO_InitStructure.Pin = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2;
	YuWei_GPIO_InitStructure.Mode = GPIO_MODE_INPUT;
	YuWei_GPIO_InitStructure.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(GPIOB, &YuWei_GPIO_InitStructure);	

	YuWei_GPIO_InitStructure.Pin = GPIO_PIN_0;
	HAL_GPIO_Init(GPIOA, &YuWei_GPIO_InitStructure);
}

bool Key1_HasBeenClicked(void)
{
	bool clicked = false;
	if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0) == GPIO_PIN_RESET)
	{
		delay_us(50);
		while(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0) == GPIO_PIN_RESET);
		delay_us(50);
		clicked = true;
	}
	return clicked;
}

bool Key2_HasBeenClicked(void)
{
	bool clicked = false;
	if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1) == GPIO_PIN_RESET)
	{
		delay_us(50);
		while(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1) == GPIO_PIN_RESET);
		delay_us(50);
		clicked = true;
	}
	return clicked;
}

bool Key3_HasBeenClicked(void)
{
	bool clicked = false;
	if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_2) == GPIO_PIN_RESET)
	{
		delay_us(50);
		while(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_2) == GPIO_PIN_RESET);
		delay_us(50);
		clicked = true;
	}
	return clicked;
}

bool Key4_HasBeenClicked(void)
{
	bool clicked = false;
	if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == GPIO_PIN_RESET)
	{
		delay_us(50);
		while(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == GPIO_PIN_RESET);
		delay_us(50);
		clicked = true;
	}
	return clicked;
}

uint8_t Key_Scan(void)
{
	uint8_t keyValue = 0;
	
	if(Key1_HasBeenClicked())
	{
		keyValue = 1;
	}
	
	if(Key2_HasBeenClicked())
	{
		keyValue = 2;
	}
	
	if(Key3_HasBeenClicked())
	{
		keyValue = 3;
	}
	
	if(Key4_HasBeenClicked())
	{
		keyValue = 4;
	}
	
	return keyValue;
}
