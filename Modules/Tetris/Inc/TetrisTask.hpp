#pragma once
#include "TetrisLogic.hpp"
//#define DEBUG_TETRIS

namespace tetris
{
constexpr uint32_t TETRIS_HIGH_DELAY 	= 500;
constexpr uint32_t TETRIS_LOW_DELAY 	= 100;
constexpr uint32_t SQUARE_RADIUS 		= 3;
constexpr uint32_t SIDE_SQUARE 			= 15;

void TetrisTask();
bool TetrisButtonHandler(tetris::TetrisFigure& figure, uint32_t& delay);
void PrintTetrisField(tetris::block_t& myBlock);
void ErasePrevFigure(const tetris::TetrisFigure& figure);
void PrintTetrisFigure(const tetris::TetrisFigure& figure);
void PrintTetrisInterface();
void PrintNextFigure(const tetris::TetrisFigure& figure);
void PrintRowNPoint(const size_t& points, const size_t& row);
}
