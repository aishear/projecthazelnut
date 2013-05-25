#pragma once
#include "stdafx.h"
#include "ButtonComponent.h"

ButtonComponent::ButtonComponent(unsigned id, std::function<void ()> action, sf::Sprite& sprite, sf::Vector2f position) 
	: _id(id), _action(action), _sprite(sprite)
{
	_sprite.setPosition(position);
}

ButtonComponent::~ButtonComponent() {

}

void ButtonComponent::performAction(){
	_action();
}

void ButtonComponent::draw(sf::RenderWindow& rw) {
	rw.draw(_sprite);
}