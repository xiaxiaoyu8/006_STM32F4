#ifndef __MAIN_H
    #define __MAIN_H
    
    #include "system.h" // º¬#include "stm32f4xx.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdint.h>
    #include <stdbool.h>
    #include <string.h>
    #include <math.h>
    
    
    typedef unsigned char         u8;
    typedef unsigned short int    u16;
    typedef unsigned int          u32;
    typedef unsigned long int     u64;

    typedef enum
    {
        I2C_OK = 0,
        I2C_ERROR = 1U
    } I2C_State;

    typedef enum
    {
        ACK_YES = 0,
        ACK_NO = 1U
    } ACK_State;

    typedef enum
    {
        AGAIN_NO = 0,
        AGAIN_YES = 1U
    } AGAIN_State;

#endif
