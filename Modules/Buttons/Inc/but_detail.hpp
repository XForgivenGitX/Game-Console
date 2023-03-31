#pragma once
#include <unordered_map>
#include "but_main.hpp"

namespace but{
struct ButtonDef
{
	GPIO_TypeDef* Port_;
	uint16_t Pin_;
	GPIO_PinState ReleaseState_;
//___
	uint16_t index;
};

struct ButtonCounters
{
	uint32_t ShortClickCount_{};
	uint32_t HoldClickCount_{};
	uint32_t PinStateCount_{};
};

class ButtonWrapper : public ButtonDef, private ButtonCounters
{
	/////////////////////////////////////
	uint32_t TimeBounce_{};
	uint32_t SetTime_{};
	ButtonState ButtonState_ = ButtonState::NEVERMIND;

	/////////////////////////////////////
	ButtonWrapper(GPIO_TypeDef* Port_, uint16_t Pin_, GPIO_PinState Default_) : ButtonDef{Port_, Pin_, Default_} {}

	/////////////////////////////////////
	uint32_t DurationTime() const;
	bool ReadPin() const;
	bool GetButtonState() const;
public:
	friend class ButtonControlBlock;
	/////////////////////////////////////
	uint32_t CurrentСlick_{};
	LogicState LogicState_ = LogicState::NONE;

private:
	void NevermindHandle(bool PinState);
	void PressBounceHandle(bool PinState);
	void SliceWaitHandle(bool PinState);
	void ReleaseBounceHandle(bool PinState);
};


class ButtonControlBlock
{
	static std::list<ButtonWrapper> myButtons;

public:
	static ButtonWrapper* CreateButton(GPIO_TypeDef* Port, uint16_t Pin, GPIO_PinState Default);
	static void ButtonHandler();
	ButtonControlBlock() = delete;
};

}
