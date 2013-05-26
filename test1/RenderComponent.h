#pragma once
#include "stdafx.h"
#include "Component.h"

using namespace std;

class RenderComponent : public Component {
public:
	RenderComponent(unsigned id, sf::Sprite& sprite);
	~RenderComponent();

	void updatePosition(sf::Vector2f position);
	void draw(sf::RenderWindow& rw);
	void changeSize(float factorX, float factorY);

private:
	sf::Sprite _sprite;
};