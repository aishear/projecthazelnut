#pragma once
#include "stdafx.h"
#include "GravBody.h"
#include "IDrawable.h"

class GameObject : public GravBody, public IDrawable {
public:

	GameObject(sf::Vector2f position, sf::Vector2f initialDelta, float mass, sf::Sprite& sprite);
	virtual void draw(sf::RenderWindow& rw);
	virtual void updateSprite();

private:
	sf::Sprite _sprite;
};