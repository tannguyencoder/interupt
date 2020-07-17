#ifndef __DELAY_H
#define __DELAY_H 
#include "Lib.h"

void Systick_Configuration(void);
void Delay(uint32_t time);
void TimingDelay_Decrement(void);

#endif
