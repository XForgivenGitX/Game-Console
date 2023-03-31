#pragma once
#include "but_main.hpp"
namespace but{

typedef uint16_t Definition;
constexpr Definition SHORT_CLICK 					= 50;
constexpr Definition HOLD_CLICK  					= 350;
constexpr Definition TIME_AFTER_BOUNCE    			= 10;
constexpr Definition DEFAULT_TIME_BOUNCE  			= 30;
constexpr Definition DELAY_BETWEEN_DOUBLE_CLICK  	= 200;
}

enum class LogicState
{
	NONE, WAS_PRESSED, WAS_HOLDED, WAS_SHORT_PRESSED, WAS_RELEASED
};
enum class ButtonState
{
	NEVERMIND, PRESS_BOUNCE, SLICE_WAIT, RELEASE_BOUNCE,
};

