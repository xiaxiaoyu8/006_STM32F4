#include "stm32f4xx.h"

typedef unsigned int u32;   //�����ض��� unsigned int -- u32


/*******************************************************************************
�Զ�������궨��
*******************************************************************************/

#define CPU_FREQ_MHZ 168 //F407��Ƶ168MHz


// ����ѭ�������������ʱ��ÿ��ѭ����Լ�� 4 �����ڣ�
/*******************************************************************************
* �� �� ��         : delay
* ��������		   : ��ʱ������ͨ��whileѭ��ռ��CPU���ﵽ��ʱ����
* ��    ��         : i
* ��    ��         : ��
*******************************************************************************/
// ������ʱ����
void delay_ms(u32 delaytime)
{
    u32 i, j;
    for(i = 0; i < delaytime; i++)
    {
        for(j = 0; j < CPU_FREQ_MHZ * 1000 / 4 / 14; j++) // 168MHz�´�Լ1ms
        {
        }
    }
}

// ΢����ʱ����
void delay_us(u32 delaytime)
{
    u32 i, j;
    for(i = 0; i < delaytime; i++)
    {
        for(j = 0; j < CPU_FREQ_MHZ / 4 / 14 * 4 /7; j++) // 168MHz�´�Լ1us
        {
        }
    }
}


void SystemInit(void)
{
	
}


void LEDS_TurnOffAll(void)
{
	GPIOF_BSRR = (1<<(9)) | (1<<(10)) | (1<<(11));
}


void LEDS_OnlyLight(int id)//id��ΧΪ[0,2]
{
	GPIOF_BSRR=(1<<(16+id +9));
}

void LEDS_R_OnlyLight(void)
{
	GPIOF_BSRR=(1<<(16+9));
}


void LEDS_G_OnlyLight(void)
{
	GPIOF_BSRR=(1<<(16+10));
}


void LEDS_B_OnlyLight(void)
{
	GPIOF_BSRR=(1<<(16+11));
}

/*******************************************************************************
* �� �� ��         : main
* ��������		   : ������
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
int main()
{
	
	/*
	F9  - R
	F10 - G
	F11 - B
	*/
	RCC_AHB1ENR |= 1<<5;
	GPIOF_MODER = (1<<(2*9)) | (1<<(2*10)) | (1<<(2*11));
	
	LEDS_TurnOffAll();
	int i;
	while(1)
	{
		for(i=0;i<3;i++)
		{
			LEDS_OnlyLight(i);
			delay_us(5000000);
			LEDS_TurnOffAll();
		}
	}
}





