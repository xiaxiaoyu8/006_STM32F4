#define PERIPH_BASE      ((unsigned int)0x40000000)
	
#define AHB1PERIPH_BASE  (PERIPH_BASE + 0x00020000)

#define GPIOF_BASE       (AHB1PERIPH_BASE + 0x1400)
#define GPIOF_MODER 	 *(unsigned int*)(GPIOF_BASE+0x00)
#define GPIOF_BSRR 		 *(unsigned int*)(GPIOF_BASE+0x18)
	

#define RCC_BASE 		(AHB1PERIPH_BASE + 0x3800)
#define RCC_AHB1ENR 	*(unsigned int*)(RCC_BASE+0x30)
	

