#pragma once
#include "stdafx.h"

using namespace std;

class RenderComponent {
public:
	RenderComponent(unsigned id, sf::Sprite& sprite);
	~RenderComponent();

	void updatePosition(sf::Vector2f position);
	void draw(sf::RenderWindow& rw);
	void changeSize(float factorX, float factorY);

private:
	sf::Sprite _sprite;
	unsigned _id;
};