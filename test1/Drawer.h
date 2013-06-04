#pragma once
#include "stdafx.h"
#include "IDrawable.h"
#include "GameObject.h"

class Drawer {
public:
	static void drawAll(const std::vector<GameObject*>::iterator& begin, const std::vector<GameObject*>::iterator& end, int numObjects, sf::RenderWindow& rw);
	static void updateObjects(const std::vector<GameObject*>::iterator& begin, const std::vector<GameObject*>::iterator& end);
	
private:
	static sf::VertexArray _trails;
};