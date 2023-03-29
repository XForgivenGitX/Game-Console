#include <SnakeTask.hpp>
using namespace snake;

extern but::ButtonWrapper* but1;
extern but::ButtonWrapper* but2;
extern but::ButtonWrapper* but3;
extern but::ButtonWrapper* but4;


void snake::printSnakeSquare(SnakeNode& sn)
{
	tft_fillRoundRect(sn.Coord.X * SIZE_SIDE_SQUARE, sn.Coord.Y *
			SIZE_SIDE_SQUARE, SIZE_SIDE_SQUARE, SIZE_SIDE_SQUARE, RADIUS_ROUNDING, sn.color);
}

void snake::SnakeTask()
{
	ClassicSnake SnakeObj(Coordinate{0, 0}, Coordinate{20, 15},
			ILI9341_BLACK, ILI9341_GREEN, ILI9341_DARKRED, ILI9341_BLUE);
	uint32_t time = HAL_GetTick();
	directions tmpDir;
	uint32_t currentDelay = INIT_SPEED_GAME;

	tft_fillScreen(ILI9341_BLUE);
	printSnakeSquare(SnakeObj.fruitCoordinate);

	while(!SnakeObj.CheckSnakeCollision(*SnakeObj.mySnake.rbegin()))
	{
		SnakeObj.Move();
		if(SnakeObj.CheckFruit())
		{
			SnakeObj.GenerateNewFruit();
			SnakeObj.AddNodeToEnd();
			while(SnakeObj.CheckSnakeCollision(SnakeObj.fruitCoordinate))
				SnakeObj.GenerateNewFruit();
			printSnakeSquare(SnakeObj.fruitCoordinate);
			//if(!((SnakeObj.mySnake.size() - 1) % 3) && (currentDelay != FINAL_SPEED_GAME))
				//currentDelay -= 25;
		}
		std::for_each(SnakeObj.mySnake.begin(), SnakeObj.mySnake.end(), printSnakeSquare);
		tmpDir = SnakeObj.currentDir;
		while(computeTimeDuration(time) < currentDelay)
		{
			if(tmpDir == SnakeObj.currentDir)
				SnakeButtonHandler(SnakeObj);
		}
		time = HAL_GetTick();
	}
	tft_setTextColor(ILI9341_DARKRED);
	tft_setTextSize(6);
	tft_setCursor(0, 0);
	tft_print(int(SnakeObj.mySnake.size() - 1));
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
			SnakeTask();
	}
}

void snake::SnakeButtonHandler(ClassicSnake& cd)
{
	if((but1->LogicState_ == LogicState::WAS_PRESSED) && (cd.currentDir != directions::RIGHT)){
		cd.NewDirection(directions::LEFT);
		but1->LogicState_ = LogicState::NONE;
	}
	else if((but2->LogicState_ == LogicState::WAS_PRESSED) && (cd.currentDir != directions::DOWN)){
		cd.NewDirection(directions::UP);
		but2->LogicState_ = LogicState::NONE;
	}
	else if((but3->LogicState_ == LogicState::WAS_PRESSED) && (cd.currentDir != directions::UP)){
		cd.NewDirection(directions::DOWN);
		but3->LogicState_ = LogicState::NONE;
	}
	else if((but4->LogicState_ == LogicState::WAS_PRESSED) && (cd.currentDir != directions::LEFT)){
		cd.NewDirection(directions::RIGHT);
		but4->LogicState_ = LogicState::NONE;
	}
}
