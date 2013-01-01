#pragma once
#include "stdafx.h"

using namespace std;

class CollisionComponent {
public:
	enum ShapeType {Circle, Triangle};

	CollisionComponent(unsigned id, ShapeType shape);
	~CollisionComponent();
	
	unsigned getId() const;
	
	
private:
	ShapeType _shape;
	unsigned _id;
};