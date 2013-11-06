/*
 * Copyright 2013 Andrew Shearer <kb3luf@verizon.net>
 * MIT LICENCE - see MIT-LICENCE.txt
 * This file is part of projectHazelnut, a n-body simulation and game.
 */

#pragma once
#include "stdafx.h"
#include "Component.h"

class ComponentMap {
public:
	virtual ~ComponentMap();

	virtual void add(unsigned id, Component* c);

	virtual Component* get(unsigned id);

	virtual void remove(unsigned id);
protected:

	std::map<unsigned, Component*> _componentMap;
};
