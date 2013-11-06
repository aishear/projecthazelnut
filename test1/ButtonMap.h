/*
 * Copyright 2013 Andrew Shearer <kb3luf@verizon.net>
 * MIT LICENCE - see MIT-LICENCE.txt
 * This file is part of projectHazelnut, a n-body simulation and game.
 */

#pragma once
#include "stdafx.h"
#include "ButtonComponent.h"

using namespace std;

class ButtonMap {
public:

	ButtonMap();
	~ButtonMap();

	ButtonComponent* getButtonComponent(unsigned id);
	void addButtonComponent(unsigned id, std::function<void ()> action, sf::Rect<float> bound);
	void removeButtonComponent(unsigned id);

private:
	
	map<unsigned, ButtonComponent*> _buttonMap;
};
