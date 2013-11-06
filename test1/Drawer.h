/*
 * Copyright 2013 Andrew Shearer <kb3luf@verizon.net>
 * MIT LICENCE - see MIT-LICENCE.txt
 * This file is part of projectHazelnut, a n-body simulation and game.
 */

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
