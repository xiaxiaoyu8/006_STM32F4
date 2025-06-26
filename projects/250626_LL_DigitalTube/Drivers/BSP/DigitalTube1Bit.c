#include "DigitalTube1Bit.h"

uint8_t DigitalTube_SegmentData[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};
    
void DigitalTube1Bit_Init(void)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 
                                | GPIO_Pin_1 
                                | GPIO_Pin_2
                                | GPIO_Pin_3 
                                | GPIO_Pin_4 
                                | GPIO_Pin_5 
                                | GPIO_Pin_6 
                                | GPIO_Pin_7;
 	GPIO_Init(GPIOB, &GPIO_InitStructure);
    GPIO_WriteBit(GPIOB, GPIO_Pin_0 
                                | GPIO_Pin_1 
                                | GPIO_Pin_2
                                | GPIO_Pin_3 
                                | GPIO_Pin_4 
                                | GPIO_Pin_5 
                                | GPIO_Pin_6 
                                | GPIO_Pin_7, Bit_RESET);
}

/**
* @brief 用来显示一位数值在一位数码管内
	* @param  number: 待显示的数值
	* @param  withDot: 是否显示小数点
	* @retval 返回值无
  */
void DigitalTube1Bit_DisplayNumber(uint8_t number, uint8_t withDot)
{	
	uint8_t data = DigitalTube_SegmentData[number];
	if(withDot)
	{
		data |= 0x80;
	}
	for(uint8_t i = 0; i < 8; i ++)
	{
        GPIO_WriteBit(GPIOB, (GPIO_Pin_0 << i), (BitAction)((data & (0x01 << i)) >> i));
	}
}
