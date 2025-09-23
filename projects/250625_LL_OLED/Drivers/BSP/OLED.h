#ifndef __OLED_H
    #define __OLED_H

    #include "system.h"

    // === 引脚定义 ===
    #define OLED_SCL_Pin        GPIO_Pin_7
    #define OLED_SDA_Pin        GPIO_Pin_8 
    #define OLED_GPIO_PORT      GPIOB
    #define OLED_RCC_AHB1       RCC_AHB1Periph_GPIOB


    // === 从机地址（SSD1306默认0x3C，写地址左移1位） ===
    #define OLED_I2C_ADDR       0x78

    void OLED_Init(void);
    void OLED_Clear(void);
    void OLED_ShowChinese(uint8_t Row, uint8_t Column, char *CH);
    void OLED_ShowCharacter(uint8_t Line, uint8_t Column, char Char);
    void OLED_ShowString(uint8_t Line, uint8_t Column, char *String);
    void OLED_ShowInteger(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);
    void OLED_ShowSignedInteger(uint8_t Line, uint8_t Column, int32_t Number, uint8_t Length);
    void OLED_ShowHexInteger(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);
    void OLED_ShowBinInteger(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);
    void OLED_ShowSignedFloat(uint8_t Row, uint8_t Column, float Number, uint8_t LengthOfIntegralPart, uint8_t LengthOfDecimalPart);

#endif
