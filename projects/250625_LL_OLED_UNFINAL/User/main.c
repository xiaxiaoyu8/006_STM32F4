#include "main.h"    

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
    
    OLED_ShowString(1,3, "AA");
    while(1)
    {
//        switch(Key_scan())
//        {
//            case 0:
//                PFout(9) = 1;
//            break;
//            case 1:
//                PFout(9) = 0;
//            break;
//            case 2:
//                PFout(10) = 1;
//            break;
//            case 3:
//                PFout(10) = 0;
//            break;
//            default:
//                
//            break;
//        }
        
    }
}
