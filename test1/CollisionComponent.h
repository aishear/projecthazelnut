#pragma once
#include "stdafx.h"

using namespace std;

class CollisionComponent {
public:
	enum shapeType {Circle, Triangle};

	CollisionComponent(unsigned id, shapeType shape);
	~CollisionComponent();
	
	unsigned getId() const;
	
	
private:
	shapeType _shape;
	unsigned _id;
};