#pragma once
#include "stm32f1xx_hal.h"
#include "main.h"
#include <but_main.hpp>
#include <Adafruit_GFX.hpp>

#define PORTRAIT_ORIENTATION 	0
#define RECTANGLE_ORIENTATION 	1

#define BUTTON_FOREGROUND_COLOR ILI9341_PURPLE
#define BUTTON_BACKGROUND_COLOR ILI9341_BLACK

extern but::ButtonWrapper* but1;
extern but::ButtonWrapper* but2;
extern but::ButtonWrapper* but3;
extern but::ButtonWrapper* but4;

void MainThread();
void SysTickThread();
void MainInit();
void МenuChoice(void (**choice)());
void PrintMenuInterface();
void PrintButton(void (*choice)(), uint16_t);
void AboutChoice();
uint32_t computeTimeDuration(uint32_t time);

struct Coordinate
{
	int32_t X;
	int32_t Y;
	Coordinate(int32_t X_, int32_t Y_) : X(X_), Y(Y_) {}
};


