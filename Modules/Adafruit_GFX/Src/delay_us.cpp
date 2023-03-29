#include <delay_us.hpp>
#include <stdbool.h>
#include "main.h"



//////////////////////////////////////////////////////////////////////////
// Перенаправление указателей аппаратного таймера на собственные
//
// В таймере должны быть разрешены прерывания по переполнению ARR. Значение в ARR определяет длительность задержки в мкс

// Таймер
extern TIM_HandleTypeDef htim1;															// Фактический таймер, предделитель которого даёт 1 мкс. (если тактовая 48 МГц, Prescaler = 47)
TIM_HandleTypeDef * Delay_us_Timer_Handle = &htim1;					// Перенаправление указателя на структуру параметров

//////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////
// Функции управления таймером
//
void Delay_us_Timer_On (void)
{
		HAL_TIM_Base_Start_IT(Delay_us_Timer_Handle);
}

void Delay_us_Timer_Off (void)
{
		HAL_TIM_Base_Stop_IT(Delay_us_Timer_Handle);
}
//////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////
// Обработчик прерывания таймера
// 
volatile unsigned int Delay_us_Is_Running = false;										// Признак того, что задержка выполняется
//
void ISR_Delay_us_Timer (void)
{
	Delay_us_Timer_Off();																								// Выключение таймера
	Delay_us_Is_Running = false;																				// Сброс признака выполнения задержки
}
//////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////
// uint16_t Задержка в мкс. Не более 65535
//
void delayUS(unsigned short int time_us)
{
	Delay_us_Is_Running = true;																						// Задержка началась
	__HAL_TIM_SET_COUNTER(Delay_us_Timer_Handle, 0);											// Сброс счётного регистра
	__HAL_TIM_SET_AUTORELOAD(Delay_us_Timer_Handle, time_us);							// Задержка определяется значением в регистре ARR
	Delay_us_Timer_On();																									// Включение таймера
	while(Delay_us_Is_Running);																						// Ожидание окончания счёта
}
//////////////////////////////////////////////////////////////////////////