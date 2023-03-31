#include "but_main.hpp"
using namespace but;

std::list<ButtonWrapper> ButtonControlBlock::myButtons;

ButtonWrapper* ButtonControlBlock::CreateButton(GPIO_TypeDef* Port, uint16_t Pin, GPIO_PinState Default)
{
	static int counter = 0;
	myButtons.push_back(ButtonWrapper(Port, Pin, Default));
	myButtons.back().index = counter++;
	return &myButtons.back();
}

////////////////////////////////////////////////////////
void ButtonControlBlock::ButtonHandler()
{
	for(auto& it : myButtons)
	{
		bool PinState = it.ReadPin();
		switch(it.ButtonState_)
		{
		case ButtonState::NEVERMIND:
			it.NevermindHandle(PinState);
			break;

		case ButtonState::PRESS_BOUNCE:
			it.PressBounceHandle(PinState);
			break;

		case ButtonState::SLICE_WAIT:
			it.SliceWaitHandle(PinState);
			break;

		case ButtonState::RELEASE_BOUNCE:
			it.ReleaseBounceHandle(PinState);
			break;
		}
	}
}

