#include <TetrisTask.hpp>
#include <SnakeTask.hpp>
#include "ILI9341.hpp"

but::ButtonWrapper *but1 = but::ButtonControlBlock::CreateButton(DB4_GPIO_Port, DB4_Pin, GPIO_PIN_SET);
but::ButtonWrapper *but2 = but::ButtonControlBlock::CreateButton(DB5_GPIO_Port, DB5_Pin, GPIO_PIN_SET);
but::ButtonWrapper *but3 = but::ButtonControlBlock::CreateButton(DB6_GPIO_Port, DB6_Pin, GPIO_PIN_SET);
but::ButtonWrapper *but4 = but::ButtonControlBlock::CreateButton(DB7_GPIO_Port, DB7_Pin, GPIO_PIN_SET);

void MainInit()
{
	tft_begin();
	tft_setRotation(RECTANGLE_ORIENTATION);
}

void AboutChoice()
{

}

void PrintMenuInterface()
{
	tft_fillScreen(ILI9341_CYAN);
	tft_fillRoundRect(80, 30, 160, 50, 5, ILI9341_BLACK);
	tft_fillRoundRect(80, 95, 160, 50, 5, ILI9341_BLACK);
	tft_fillRoundRect(80, 160, 160, 50, 5, ILI9341_BLACK);

	tft_setTextSize(3);
	PrintButton(snake::SnakeTask, ILI9341_WHITE);
	PrintButton(tetris::TetrisTask, ILI9341_WHITE);
	PrintButton(AboutChoice, ILI9341_WHITE);
}

void PrintButton(void (*choice)(), uint16_t ColorText)
{
	if(choice == snake::SnakeTask)
	{
		tft_fillRoundRect(84, 34, 152, 42, 5, BUTTON_FOREGROUND_COLOR);
		tft_setCursor(114, 46);
		tft_setTextColor(ColorText);
		tft_print("SNAKE");
	}
	else if(choice == tetris::TetrisTask)
	{
		tft_fillRoundRect(84, 99, 152, 42, 5, BUTTON_FOREGROUND_COLOR);
		tft_setCursor(106, 111);
		tft_setTextColor(ColorText);
		tft_print("TETRIS");
	}
	else if(choice == AboutChoice)
	{
		tft_fillRoundRect(84, 164, 152, 42, 5, BUTTON_FOREGROUND_COLOR);
		tft_setCursor(114, 176);
		tft_setTextColor(ColorText);
		tft_print("ABOUT");
	}
}

void МenuChoice(void (**choice)())
{
	if(but1->LogicState_ == LogicState::WAS_RELEASED)
	{
		PrintButton(*choice, ILI9341_WHITE);
		*choice = snake::SnakeTask;
		PrintButton(*choice, ILI9341_BLUE);
		but1->LogicState_ = LogicState::NONE;
	}
	else if(but2->LogicState_ == LogicState::WAS_RELEASED)
	{
		PrintButton(*choice, ILI9341_WHITE);
		*choice = tetris::TetrisTask;
		PrintButton(*choice, ILI9341_BLUE);
		but2->LogicState_ = LogicState::NONE;
	}
	else if(but3->LogicState_ == LogicState::WAS_RELEASED)
	{
		PrintButton(*choice, ILI9341_WHITE);
		*choice = AboutChoice;
		PrintButton(*choice, ILI9341_BLUE);
		but3->LogicState_ = LogicState::NONE;
	}
	else if(but4->LogicState_ == LogicState::WAS_RELEASED)
	{
		if(choice != nullptr)
		{
			(*choice)();
			PrintMenuInterface();
		}
		but4->LogicState_ = LogicState::NONE;
	}

}
void MainThread()
{
	MainInit();
	PrintMenuInterface();
	void (*choice)() = nullptr;
	while(true)
	{
		МenuChoice(&choice);
	}
}

void SysTickThread()	//called every millisecond
{
	but::ButtonControlBlock::ButtonHandler();
}

uint32_t computeTimeDuration(uint32_t time)
{
	return HAL_GetTick() - time;
}

