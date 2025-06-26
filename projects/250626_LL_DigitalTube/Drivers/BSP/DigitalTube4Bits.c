#include "DigitalTube4Bits.h"
#include "SysTick.h"

void DigitalTube4Bits_Init(void)
{
	DigitalTube1Bit_Init();
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13;
 	GPIO_Init(GPIOB, &GPIO_InitStructure);
    
    GPIO_WriteBit(GPIOB, GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13, Bit_RESET);
}

void DigitalTube4Bits_DisplayIntergel(uint16_t number)
{
	uint16_t N3 = number / 1000 % 10;
	uint16_t N2 = number / 100 % 10;
	uint16_t N1 = number / 10 % 10;
	uint16_t N0 = number / 1 % 10;
	
	uint32_t delaytimes = 2000;
    
	GPIO_WriteBit(GPIOC, GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13, Bit_SET);
	GPIO_WriteBit(GPIOC, GPIO_Pin_13, Bit_RESET);
	DigitalTube1Bit_DisplayNumber(N3,0);
	delay_us(delaytimes);
	
	GPIO_WriteBit(GPIOC, GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13, Bit_SET);
	GPIO_WriteBit(GPIOC, GPIO_Pin_12, Bit_RESET);
	DigitalTube1Bit_DisplayNumber(N2,0);
	delay_us(delaytimes);
	
	GPIO_WriteBit(GPIOC, GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13, Bit_SET);
	GPIO_WriteBit(GPIOC, GPIO_Pin_11, Bit_RESET);
	DigitalTube1Bit_DisplayNumber(N1,0);
	delay_us(delaytimes);
	
	GPIO_WriteBit(GPIOC, GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13, Bit_SET);
	GPIO_WriteBit(GPIOC, GPIO_Pin_10, Bit_RESET);
	DigitalTube1Bit_DisplayNumber(N0,0);
	delay_us(delaytimes);
}
