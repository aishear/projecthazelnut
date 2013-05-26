#pragma once
#include "stdafx.h"
#include "RenderComponent.h"
#include "Game.h"

RenderComponent::RenderComponent(unsigned id, sf::Sprite& sprite) 
	: Component(id), _sprite(sprite)
{

}

RenderComponent::~RenderComponent() {

}

void RenderComponent::updatePosition(sf::Vector2f position) {
	_sprite.setPosition(position);
}

void RenderComponent::draw(sf::RenderWindow& rw) {
	rw.draw(_sprite);
	
	
	/*
	//debug circle drawing
	float width = Game::getCollisionMap().getCollisionComponent(_id)->getWidth();
	sf::CircleShape s(width/2);	
	s.setOrigin(width/2, width/2);
	s.setPosition(position);
	rw.draw(s);
	*/
}

void RenderComponent::changeSize(float factorX, float factorY) {
	_sprite.setScale(factorX, factorY);
}
