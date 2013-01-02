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