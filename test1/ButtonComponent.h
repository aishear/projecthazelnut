/*
 * Copyright 2013 Andrew Shearer <kb3luf@verizon.net>
 * MIT LICENCE - see MIT-LICENCE.txt
 * This file is part of projectHazelnut, a n-body simulation and game.
 */

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
