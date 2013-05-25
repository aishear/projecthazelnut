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

	float width = Game::getCollisionMap().getCollisionComponent(_id)->getWidth();
	sf::CircleShape s(width/2);

	/*
	//debug circle drawing
	s.setOrigin(width/2, width/2);
	s.setPosition(position);
	rw.draw(s);
	*/
}

void RenderComponent::changeSize(float factorX, float factorY) {
	_sprite.setScale(factorX, factorY);
}
