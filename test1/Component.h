/*
 * Copyright 2013 Andrew Shearer <kb3luf@verizon.net>
 * MIT LICENCE - see MIT-LICENCE.txt
 * This file is part of projectHazelnut, a n-body simulation and game.
 */

#pragma once
#include "stdafx.h"

class Component {
public:
	virtual ~Component() {}

protected:
	Component(unsigned id) : _id(id)
	{
	}
	unsigned _id;
};
