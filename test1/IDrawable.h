#pragma once
#include "stdafx.h"

class IDrawable {
public:

	virtual ~IDrawable() {}

	virtual void draw(sf::RenderWindow& rw) = 0;

};