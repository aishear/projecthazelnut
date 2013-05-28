#pragma once
#include "stdafx.h"
#include "Planet.h"

class Gravity {
public:
	static void updateDeltas(std::vector<GameObject>& objects);
	static void updatePositions(const std::vector<GameObject>::iterator& begin, const std::vector<GameObject>::iterator& end, float deltaTime);
};