#pragma once
#include "stdafx.h"

class ButtonComponent {
public:
	ButtonComponent(unsigned id, std::function<void ()> action, sf::Sprite& sprite, sf::Vector2f position);
	~ButtonComponent();

	void performAction();
	void draw(sf::RenderWindow& rw);
private:
	std::function<void ()> _action;
	unsigned _id;
	sf::Sprite& _sprite;
};