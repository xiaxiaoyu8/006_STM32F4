#ifndef __OLED_H_
	#define __OLED_H_
    #include "stm32f4xx_hal.h"
	
	#define OLED_ADDRESS 0x78

	void OLED_Init(void);
	void OLED_Clear(void);
	void OLED_ShowCharacter(uint8_t Row, uint8_t Column, char Character);
	void OLED_ShowString(uint8_t Row, uint8_t Column, char *String);
	void OLED_ShowInteger(uint8_t Row, uint8_t Column, uint32_t Integer, uint8_t Length);
	void OLED_ShowSignedInteger(uint8_t Row, uint8_t Column, int32_t Integer, uint8_t Length);
	void OLED_ShowHexInteger(uint8_t Row, uint8_t Column, uint32_t Integer, uint8_t Length);
	void OLED_ShowBinInteger(uint8_t Row, uint8_t Column, uint32_t Integer, uint8_t Length);
	void OLED_ShowUnsignedFloat(uint8_t Row, uint8_t Column, float Number, uint8_t LengthOfIntegralPart, uint8_t LengthOfDecimalPart);
	void OLED_ShowSignedFloat(uint8_t Row, uint8_t Column, float Number, uint8_t LengthOfIntegralPart, uint8_t LengthOfDecimalPart);
	void OLED_ShowChinese(uint8_t Row, uint8_t Column, char *CH);
#endif
