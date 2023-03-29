#ifndef __DELAY_US_H_
#define __DELAY_US_H_

#include "main.h"

void ISR_Delay_us_Timer (void);											// Обработчик прерываний таймера

extern volatile unsigned int Delay_us_Is_Running;		// Признак того, что задержка выполняется

void delayUS(unsigned short int time_us);						// uint16_t Задержка в мкс. Не более 65535

#define delay_us(x)			delayUS(x)									// Псевдоним функции задержки в микросекундах
#define delayMS(x)			HAL_Delay(x)								// Адаптация задержки Ардуино

#endif /* __DELAY_US_H_ */
