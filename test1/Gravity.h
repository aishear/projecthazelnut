#pragma once
#include "stdafx.h"
#include "Planet.h"

class Gravity {
public:
	static void updateDeltas(std::vector<GameObject>& planets);
};