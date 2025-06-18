/**
 ****************************************************************************************************
 * @file        beep.h
 * @author      正点原子团队(ALIENTEK)
 * @version     V1.0
 * @date        2021-12-30
 * @brief       蜂鸣器 驱动代码
 * @license     Copyright (c) 2020-2032, 广州市星翼电子科技有限公司
 ****************************************************************************************************
 * @attention
 *
 * 实验平台:正点原子 STM32F407开发板
 * 在线视频:www.yuanzige.com
 * 技术论坛:www.openedv.com
 * 公司网址:www.alientek.com
 * 购买地址:openedv.taobao.com
 *
 * 修改说明
 * V1.0 20211230
 * 第一次发布
 *
 ****************************************************************************************************
 */

#ifndef __BEEP_H
#define __BEEP_H

#include "./SYSTEM/sys/sys.h"

/******************************************************************************************/
/* 引脚 定义 */

#define BEEP_GPIO_PORT                  GPIOF
#define BEEP_GPIO_PIN                   SYS_GPIO_PIN8
#define BEEP_GPIO_CLK_ENABLE()          do{ RCC->AHB1ENR |= 1 << 5; }while(0)   /* PF口时钟使能 */

/******************************************************************************************/

/* 蜂鸣器控制 */
#define BEEP(x)         sys_gpio_pin_set(BEEP_GPIO_PORT, BEEP_GPIO_PIN, x)

/* BEEP取反定义 */
#define BEEP_TOGGLE()   do{ BEEP_GPIO_PORT->ODR ^= BEEP_GPIO_PIN; }while(0)     /* BEEP = !BEEP */


void beep_init(void);   /* 初始化蜂鸣器 */

#endif

















