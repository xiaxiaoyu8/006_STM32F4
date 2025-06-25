#ifndef __OLED_H
    #define __OLED_H

    #include "stm32f4xx.h"

    // === 引脚定义 ===
    #define OLED_SCL_Pin        GPIO_Pin_10
    #define OLED_SDA_Pin        GPIO_Pin_11
    #define OLED_GPIO_PORT      GPIOF
    #define OLED_RCC_AHB1       RCC_AHB1Periph_GPIOF


    // === 从机地址（SSD1306默认0x3C，写地址左移1位） ===
    #define OLED_I2C_ADDR       0x78

    // === API函数声明 ===
    void OLED_Init(void);
    void OLED_Clear(void);
    void OLED_ShowCharacter(uint8_t Line, uint8_t Column, char Char);
    void OLED_ShowString(uint8_t Line, uint8_t Column, char *String);
    void OLED_ShowNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);
    void OLED_ShowSignedNum(uint8_t Line, uint8_t Column, int32_t Number, uint8_t Length);
    void OLED_ShowHexNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);
    void OLED_ShowBinNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);

#endif
