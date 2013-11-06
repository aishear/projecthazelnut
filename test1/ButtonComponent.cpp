/*
 * Copyright 2013 Andrew Shearer <kb3luf@verizon.net>
 * MIT LICENCE - see MIT-LICENCE.txt
 * This file is part of projectHazelnut, a n-body simulation and game.
 */

#pragma once
#include "stdafx.h"
#include "ButtonComponent.h"

ButtonComponent::ButtonComponent(unsigned id, std::function<void ()> action, sf::Rect<float> bound) 
	: _id(id), _action(action)
{
}

ButtonComponent::~ButtonComponent() {

}

void ButtonComponent::performAction(){
	_action();
}
