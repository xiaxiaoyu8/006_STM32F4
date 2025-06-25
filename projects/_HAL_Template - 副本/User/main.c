#include "./SYSTEM/sys.h"
#include "./SYSTEM/usart.h"
#include "./SYSTEM/delay.h"
#include "./BSP/led.h"
#include "./BSP/key.h"
#include "./BSP/oled.h"

uint8_t CursorRowId = 1;
uint8_t LevelID = 0;
uint8_t Timer = 0;

void Show_Provinces(void)
{
	LevelID = 0;
	if(Timer % 10 < 5)
	{
		OLED_ShowString(CursorRowId,1,"?");
	}
	else
	{
		OLED_ShowString(CursorRowId,1,"   ");
	}
	OLED_ShowString(1,4,"???");
	OLED_ShowString(2,4,"???");
	OLED_ShowString(3,4,"???");
	OLED_ShowString(4,4,"???");
}

void Show_Cities(uint8_t provinceId)
{
	LevelID = 1;
	OLED_ShowString(1,1,"?");
	OLED_ShowString(2,1,"?");
	OLED_ShowString(3,1,"?");
	OLED_ShowString(4,1,"?");
	switch(provinceId)
	{
		case 1:
		{
			OLED_ShowString(1,4,"???");
			OLED_ShowString(2,4,"???");
			OLED_ShowString(3,4,"???");
			OLED_ShowString(4,4,"???");
			break;
		}
		case 2:
		{
			OLED_ShowString(1,4,"???");
			OLED_ShowString(2,4,"???");
			OLED_ShowString(3,4,"???");
			OLED_ShowString(4,4,"???");
			break;
		}
		case 3:
		{
			OLED_ShowString(1,4,"???");
			OLED_ShowString(2,4,"???");
			OLED_ShowString(3,4,"???");
			OLED_ShowString(4,4,"???");
			break;
		}
		case 4:
		{
			OLED_ShowString(1,4,"???");
			OLED_ShowString(2,4,"???");
			OLED_ShowString(3,4,"???");
			OLED_ShowString(4,4,"???");
			break;
		}
		default:
		{
			OLED_Clear();
			OLED_ShowString(1,4,"?????!");
			break;
		}
	}
}


int main(void)
{
    uint8_t len;
    uint16_t times = 0;
    
    HAL_Init();                             /* 初始化HAL库 */
    sys_stm32_clock_init(336, 8, 2, 7);     /* 设置时钟,168Mhz */
    delay_init(168);                        /* 延时初始化 */
    usart_init(115200);                     /* 串口初始化为115200 */
    OLED_Init();                             /* 初始化LED */

//    while(1)
//    {
//       if (g_usart_rx_sta & 0x8000)         /* 接收到了数据? */
//        {
//            len = g_usart_rx_sta & 0x3fff;  /* 得到此次接收到的数据长度 */
//            printf("\r\n您发送的消息为:\r\n");

//            HAL_UART_Transmit(&g_uart1_handle,(uint8_t*)g_usart_rx_buf,len,1000);    /* 发送接收到的数据 */
//            while(__HAL_UART_GET_FLAG(&g_uart1_handle,UART_FLAG_TC)!=SET);           /* 等待发送结束 */
//            printf("\r\n\r\n");             /* 插入换行 */
//            g_usart_rx_sta = 0;
//        }
//        else
//        {
//            times++;

//            if (times % 5000 == 0)
//            {
//                printf("\r\n正点原子 STM32开发板 串口实验\r\n");
//                printf("正点原子@ALIENTEK\r\n\r\n\r\n");
//            }

//            if (times % 200 == 0) printf("请输入数据,以回车键结束\r\n");

//            if (times % 30  == 0) LED0_TOGGLE(); /* 闪烁LED,提示系统正在运行. */

//            delay_ms(10);
//        }
 while (1)
  {
		if(Timer < UINT8_MAX)
		{
			Timer ++;
		}
		else
		{
			Timer = 0;
		}
				
		if(LevelID == 0)
		{
			if(Key1_HasBeenClicked())
			{
				OLED_ShowString(CursorRowId,1,"  ");
				if(CursorRowId > 1)
				{
					CursorRowId --;
				}
				else
				{
					CursorRowId = 4;
				}
			}
			
			if(Key2_HasBeenClicked())
			{
				OLED_ShowString(CursorRowId,1,"  ");
				if(CursorRowId < 4)
				{
					CursorRowId ++;
				}
				else
				{
					CursorRowId = 1;
				}
			}
			
			Show_Provinces();
			
			if(Key3_HasBeenClicked())
			{
				Show_Cities(CursorRowId);
			}
		}
		else
		{
			if(Key4_HasBeenClicked())
			{
				OLED_ShowString(1,1,"  ");
				OLED_ShowString(2,1,"  ");
				OLED_ShowString(3,1,"  ");
				OLED_ShowString(4,1,"  ");
				Show_Provinces();
			}
		}
    }
}

