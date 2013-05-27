#pragma once
#include "stdafx.h"
#include "IDrawable.h"
#include "GameObject.h"

class Drawer {
public:
	static void drawAll(const std::vector<GameObject>::const_iterator& begin, const std::vector<GameObject>::const_iterator& end, sf::RenderWindow& rw);
};