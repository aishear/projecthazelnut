#pragma once
#include "stdafx.h"

class ButtonComponent {
public:
	ButtonComponent(unsigned id, std::function<void ()> action, sf::Rect<float> bound);
	~ButtonComponent();

	void performAction();
private:
	std::function<void ()> _action;
	unsigned _id;
};