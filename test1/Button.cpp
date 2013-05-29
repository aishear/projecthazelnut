#pragma once
#include "stdafx.h"
#include "Button.h"

Button::Button(sf::Rect<float> & bound, sf::Sprite & sprite, std::function< void ()> action)
	: _bound(bound), _sprite(sprite), _action(action)
{
	_sprite.setPosition(bound.left, bound.top);
}

void Button::draw(sf::RenderWindow & rw) {
	rw.draw(_sprite);
}

void Button::performAction() {
	_action();
}

bool Button::containsPoint(float x, float y) {
	return _bound.contains(x, y);
}

void Button::setId(SLOTMAP_ID id) {
	_id = id;
}

SLOTMAP_ID Button::getId() {
	return _id;
}