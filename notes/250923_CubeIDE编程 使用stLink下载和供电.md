我用Keil下载程序，5V给开发板3.3V引脚供电，正常烧录正常亮灯
但是我用cubeIDE烧录，同样接3.3V，但是程序根本跑不动
程序倒是可以下载进去
随后，我用ST-link的5V接开发板的5V引脚，LED按照程序逻辑亮灯，但是极其微弱
拔掉5V供电, 改用DC5V火牛供电, LED正常亮度工作

STM32F407ZGT6麒麟开发板,  CubeIDE正常开发顺序:
PA13 - DIO
PA14 - CLK
5V   - 5V   供电不足,使用DC5V可行,也可选用Keil开发
GND  - GND

