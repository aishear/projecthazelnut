/*
 * Copyright 2013 Andrew Shearer <kb3luf@verizon.net>
 * MIT LICENCE - see MIT-LICENCE.txt
 * This file is part of projectHazelnut, a n-body simulation and game.
 */

#pragma once
#include "stdafx.h"

using namespace std;

class CollisionComponent {
public:
	enum ShapeType {Circle, Triangle};

	CollisionComponent(unsigned id, ShapeType shape, float width, float height);
	~CollisionComponent();
	
	void setWidth(float width);
	void setHeight(float height);

	unsigned getId() const;
	float getWidth() const;
	float getHeight() const;
	
private:
	ShapeType _shape;
	float _width;
	float _height;
	unsigned _id;
};
