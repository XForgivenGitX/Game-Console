#pragma once
#include <SnakeLogic.hpp>

namespace snake
{
constexpr uint32_t SIZE_SIDE_SQUARE = 15;
constexpr uint32_t RADIUS_ROUNDING = 2;
constexpr uint32_t INIT_SPEED_GAME = 200;
constexpr uint32_t FINAL_SPEED_GAME = 100;

void SnakeTask();
void printSnakeSquare(snake::SnakeNode& sn);
void SnakeButtonHandler(snake::ClassicSnake&);
void printSquare(snake::SnakeNode&);
void SnakeInterface();
}
