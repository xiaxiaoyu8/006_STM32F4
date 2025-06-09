#include "delay.h"

void Delay_Ms(u32 delaytime)
{
    u32 i, j;
    for(i = 0; i < delaytime; i++)
    {
        for(j = 0; j < CPU_FREQ_MHZ * 1000 / 4 / 14; j++) // 168MHz下大约1ms
        {
        }
    }
}

void Delay_Us(u32 delaytime)
{
    u32 i, j;
    for(i = 0; i < delaytime; i++)
    {
        for(j = 0; j < CPU_FREQ_MHZ / 4 / 14 * 4 /7; j++) // 168MHz下大约1us
        {
        }
    }
}
