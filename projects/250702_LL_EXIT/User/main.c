#include "system.h"
#include "systick.h"
#include "delay.h"
#include "key.h"
#include "led.h"
#include "OLED.h"

int main()
{
    Delay_Init();
    Key_Init();
    LED_Init();
    OLED_Init();
    SysTick_Init(168);
    
//    OLED_ShowString(1,1,"1234567890123456");
    OLED_ShowChinese(1,5,"北京时间");
//    OLED_ShowString(1,1, "Key1:");
    OLED_ShowString(2,5, "hh-MM-SS");
    OLED_ShowString(3,7,  ":");
    OLED_ShowString(3,10, ":");
//    OLED_ShowString(3,1, "Key3:");
//    OLED_ShowString(4,1, "Key4:");
    
    u8 hh = 20;
    u8 mm = 04;
    u8 ss = 55;
    u8 count4 = 4;
    while(1)
    {
        switch(Key_scan())
        {
            case 0:
                hh++;
            break;
            case 1:
                mm++;
            break;
            case 2:
                ss++;
            break;
            case 3:
                count4--;
            break;
            default:
                
            break;
        }
        ss++;
        if(ss>=60)
        {
            mm++;
            ss = 0;
        }
        if(mm>=60)
        {
            hh++;
            hh = 0;
        }
        if(hh>=24)
        {
            hh = 0;
            mm = 0;
            ss = 0;
        }
//        OLED_ShowInteger(1,7,count1,3);
//        OLED_ShowInteger(2,7,count2,3);
//        OLED_ShowInteger(3,7,count3,3);
//        OLED_ShowInteger(4,7,count4,3);
        OLED_ShowInteger(3,5, hh,2);
        OLED_ShowInteger(3,8, mm,2);
        OLED_ShowInteger(3,11, ss,2);
        delay_ms(400);
        
        
        
        
    }
}
