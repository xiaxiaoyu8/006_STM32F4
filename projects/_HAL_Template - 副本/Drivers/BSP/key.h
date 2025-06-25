#ifndef __KEY_H
	#define __KEY_H
    #include "stm32f4xx_hal.h"
	#include <stdbool.h>

	void Key_Init(void);
	bool Key1_HasBeenClicked(void);
	bool Key2_HasBeenClicked(void);
	bool Key3_HasBeenClicked(void);
	bool Key4_HasBeenClicked(void);
#endif
