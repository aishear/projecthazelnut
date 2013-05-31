#pragma once
#include "stdafx.h"
#include "IDrawable.h"
#include "GameObject.h"

class Drawer {
public:
	static void drawAll(const std::vector<GameObject*>::iterator& begin, const std::vector<GameObject*>::iterator& end, sf::RenderWindow& rw);
	static void updateGraphics(const std::vector<GameObject*>::iterator& begin, const std::vector<GameObject*>::iterator& end);
};