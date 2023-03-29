#pragma once
#include <vector>
#include <algorithm>
#include <cmath>
#include <random>
#include <list>
#include <MainThread.hpp>


/*
 * 1 add const
 * 2 change structure
 * 3 add namespace
 * 4 remove printfigure-function overload
 * 5...
 *
 * */
namespace tetris
{
constexpr auto ROW_OF_FIELD			= 20;
constexpr auto HIDDEN_ROW_OF_FIELD	= 4;
constexpr auto COL_OF_FIELD			= 10;//21
constexpr auto QUANTITY_FIGURE		= 7;

struct PartTetrisBlock;
struct TetrisFigure;

using color_t = uint32_t;
using block_t = std::vector<PartTetrisBlock>;

enum Colors
{
	BACKGROUND = ILI9341_WHITE,
	FIG1COLOR = ILI9341_DARKRED,
	FIG2COLOR = ILI9341_PINK,
	FIG3COLOR = ILI9341_ORANGE,
	FIG4COLOR = ILI9341_RED,
	FIG5COLOR = ILI9341_GREEN,
	FIG6COLOR = ILI9341_PURPLE,
	FIG7COLOR = ILI9341_CYAN
};
enum class Directions{LEFT, RIGHT};

struct PartTetrisBlock
{
	bool isFeeled;
	color_t color;
	PartTetrisBlock(bool isFeeled_ = false, color_t color_ = BACKGROUND) : isFeeled(isFeeled_), color(color_) {}
};

struct TetrisManager
{
	std::vector<TetrisFigure>::iterator currentFigure;
	std::vector<TetrisFigure>::iterator nextFigure;

	block_t field{};
	bool END_OF_GAME = false;

	TetrisManager();
	size_t EraseFilledRow();
	void GenerateNewFigure();

private:
	std::vector<TetrisFigure> myFigure;
};

struct TetrisFigure
{
	block_t figure, prevFigure, initFigure;
	Coordinate initCoord, prevCoord, coord;

	TetrisManager& manager;
	const size_t side;

	TetrisFigure(block_t&& figure_, Coordinate coordFigure_, size_t sideFigure_,
		color_t colorFigure, TetrisManager& manager_);

	void Rotate();
	void MoveHorizontally(Directions direction);
	bool MoveDown();

private:
	bool CheckBoundaries();

	bool isContainsUnitInColumne(size_t icol);
	bool isContainsUnitInRow(size_t irow);
	bool isIntersectionBlocks();

	void FillFieldFigure();
	bool CheckEndGame();
};
}
std::vector<tetris::TetrisFigure> CreateFigures(tetris::TetrisManager& man);

