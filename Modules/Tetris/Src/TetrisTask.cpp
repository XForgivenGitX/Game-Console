#include "TetrisTask.hpp"
using namespace tetris;

extern but::ButtonWrapper* but1;
extern but::ButtonWrapper* but2;
extern but::ButtonWrapper* but3;
extern but::ButtonWrapper* but4;

bool tetris::TetrisButtonHandler(TetrisFigure& figure, uint32_t& delay)
{
	if(but2->LogicState_ == LogicState::WAS_PRESSED)
	{
		delay = TETRIS_LOW_DELAY;
	}
	else if(but2->LogicState_ == LogicState::NONE)
	{
		delay = TETRIS_HIGH_DELAY;
	}
	if(but1->LogicState_ == LogicState::WAS_PRESSED){
		figure.MoveHorizontally(Directions::LEFT);
		but1->LogicState_ = LogicState::NONE;
		return true;
	}
	else if(but4->LogicState_ == LogicState::WAS_PRESSED){
		figure.MoveHorizontally(Directions::RIGHT);
		but4->LogicState_ = LogicState::NONE;
		return true;
	}
	else if(but3->LogicState_ == LogicState::WAS_PRESSED){
		figure.Rotate();
		but3->LogicState_ = LogicState::NONE;
		return true;
	}
	return false;
}

void tetris::PrintTetrisFigure(const TetrisFigure& figure)
{
	int side = figure.side;
	for(int row = 0; row < side; ++row)
		for (int col = 0; col < side; ++col)
			if (figure.figure[row * side + col].isFeeled && (figure.coord.Y + row) >= HIDDEN_ROW_OF_FIELD)
			{
				tft_fillRoundRect((figure.coord.X + col) * SIDE_SQUARE,
						(figure.coord.Y + row - HIDDEN_ROW_OF_FIELD) * SIDE_SQUARE,
						SIDE_SQUARE, SIDE_SQUARE, SQUARE_RADIUS, figure.figure[row * side + col].color);
			}
}

void tetris::ErasePrevFigure(const TetrisFigure& figure)
{
	int side = figure.side;
	for (int row = 0; row < side; ++row)
		for (int col = 0; col < side; ++col)
			if (figure.prevFigure[row * side + col].isFeeled && (figure.prevCoord.Y + row) >= HIDDEN_ROW_OF_FIELD)
			{
				tft_fillRoundRect((figure.prevCoord.X + col) * SIDE_SQUARE,
						(figure.prevCoord.Y + row - HIDDEN_ROW_OF_FIELD) * SIDE_SQUARE,
						SIDE_SQUARE, SIDE_SQUARE, SQUARE_RADIUS, BACKGROUND);
			}
}

void tetris::PrintTetrisField(block_t& myBlock)
{

	for (int row = HIDDEN_ROW_OF_FIELD; row < ROW_OF_FIELD; ++row)
		for (int col = 0; col < COL_OF_FIELD; ++col)
		{
			tft_fillRoundRect(col * SIDE_SQUARE, (row - HIDDEN_ROW_OF_FIELD) * SIDE_SQUARE,
					SIDE_SQUARE, SIDE_SQUARE, SQUARE_RADIUS, myBlock[row * COL_OF_FIELD + col].color);
		}

}
void tetris::PrintNextFigure(const TetrisFigure& figure)
{
	tft_fillRoundRect(165, 30, 60, 60, SQUARE_RADIUS, ILI9341_WHITE);
	auto side = figure.side;
	for(size_t row = 0; row < side; ++row)
		for(size_t col = 0; col < side; ++col)
			if(figure.initFigure[row * side + col].isFeeled)
				tft_fillRoundRect((col + 11) * SIDE_SQUARE, (row + 2) * SIDE_SQUARE,
									SIDE_SQUARE, SIDE_SQUARE, SQUARE_RADIUS, figure.initFigure[row * side + col].color);

}
void tetris::PrintRowNPoint(const size_t& points, const size_t& row)
{
	tft_setCursor(245, 100);
	tft_print((uint16_t)points);
	tft_setCursor(257, 115);
	tft_print((uint16_t)row);
}

void tetris::TetrisTask()
{
	PrintTetrisInterface();

	TetrisManager manager;
	uint32_t delay = TETRIS_HIGH_DELAY, time = HAL_GetTick();
	size_t points = 0, erasedRows = 0;

	PrintNextFigure(*manager.nextFigure);
	while(!manager.END_OF_GAME)
	{
		if(!manager.currentFigure->MoveDown())
		{
			auto currentErasedRows = manager.EraseFilledRow();
			if(currentErasedRows)
			{
				PrintTetrisField(manager.field);
				erasedRows += currentErasedRows;
				points += currentErasedRows * 100;
			}
			manager.GenerateNewFigure();
			points += 10;
			PrintNextFigure(*manager.nextFigure);
			PrintRowNPoint(points, erasedRows);
#ifdef DEBUG_TETRIS
			HAL_UART_Transmit(&huart1, (uint8_t*)"new figure", sizeof("new figure") - 1, 1000);
#endif
		}
		else
		{
			ErasePrevFigure(*manager.currentFigure);
		}
		PrintTetrisFigure(*manager.currentFigure);
		while(computeTimeDuration(time) < delay)
		{
			if(TetrisButtonHandler(*manager.currentFigure, delay))
			{
				ErasePrevFigure(*manager.currentFigure);
				PrintTetrisFigure(*manager.currentFigure);
			}
		}
		time = HAL_GetTick();
	}
	tft_fillRoundRect(165, 30, 60, 60, SQUARE_RADIUS, ILI9341_DARKRED);
	tft_fillRoundRect(0, 200, 150, 40, 0, ILI9341_DARKRED);
	tft_setTextColor(ILI9341_BLUE);
	tft_setTextSize(2);
	tft_setCursor(0, 204);
	tft_print("HOLD 1 MENU");
	tft_setCursor(0, 224);
	tft_print("HOLD 2 REST");
	while(true)
	{
		if(but1->LogicState_ == LogicState::WAS_HOLDED)
			return;
		else if(but2->LogicState_ == LogicState::WAS_HOLDED)
			TetrisTask();
	}
}

void tetris::PrintTetrisInterface()
{
	tft_fillScreen(BACKGROUND);
	tft_fillRoundRect(150, 0, 170, 240, 0, ILI9341_DARKRED);
	tft_fillRoundRect(160, 10, 150, 125, 3, ILI9341_BLUE);
	tft_fillRoundRect(160, 140, 150, 90, 3, ILI9341_BLUE);

	tft_setTextSize(1);
	tft_setTextColor_01(ILI9341_DARKRED, ILI9341_BLUE);
	tft_setCursor(230, 20);
	tft_print("COPYRIGHT BY:");
	tft_setCursor(230, 30);
	tft_print("KUBAREV I.A.");
	tft_setCursor(230, 40);
	tft_print("KIRIN A.K.");
	tft_setCursor(230, 50);
	tft_print("ORGANISATION:");
	tft_setCursor(230, 60);
	tft_print("Ramenskiy");
	tft_setCursor(230, 70);
	tft_print("College");
	tft_setCursor(230, 80);
	tft_print("LICENSE: MIT");

	tft_setTextSize(2);
	tft_setTextColor_01(ILI9341_DARKRED, ILI9341_BLUE);
	tft_setCursor(165, 100);
	tft_print("PTS:");
	tft_setCursor(165, 115);
	tft_print("ROWS:");

	tft_setCursor(165, 145);
	tft_print("1: LEFT");
	tft_setCursor(165, 160);
	tft_print("2: BOOST");
	tft_setCursor(165, 175);
	tft_print("3: ROTATE");
	tft_setCursor(165, 190);
	tft_print("4: RIGHT");
}
