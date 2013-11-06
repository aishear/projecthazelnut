/*
 * Copyright 2013 Andrew Shearer <kb3luf@verizon.net>
 * MIT LICENCE - see MIT-LICENCE.txt
 * This file is part of projectHazelnut, a n-body simulation and game.
 */

#pragma once
#include "stdafx.h"
#include "GameObject.h"

class Gravity {
public:
	static void updateDeltas(std::vector<GameObject*>& objects, float deltaTime);
	static void updatePositions(const std::vector<GameObject*>::iterator& begin, const std::vector<GameObject*>::iterator& end, float deltaTime);
};
