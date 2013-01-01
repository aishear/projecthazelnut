#pragma once
#include "stdafx.h"
#include "RenderComponent.h"
#include "Game.h"

RenderComponent::RenderComponent(unsigned id, sf::Sprite& sprite) 
	: _id(id), _sprite(sprite)
{
}

RenderComponent::~RenderComponent() {

}

void RenderComponent::draw(sf::RenderWindow& rw) {
	auto position = Game::getPositionMap().getPositionComponent(_id)->getPosition();
	_sprite.setPosition(position);
	rw.draw(_sprite);
}