/********************************************
            蜂鸣器驱动
*********************************************/
芯片为HC32L130J8TA

#define FMQ_ON (M0P_GPIO->PDOUT |= S_7);
#define FMQ_OFF (M0P_GPIO->PDOUT &= ~S_7);

void fmq_sx(u16 counter, u16 ys) {
  for (; counter > 0; counter--) {
    FMQ_ON;
    delay_xms(ys);
    FMQ_OFF;
    delay_xms(ys);
  }
}