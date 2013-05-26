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
