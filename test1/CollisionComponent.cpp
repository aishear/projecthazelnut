#include "stdafx.h"
#include "CollisionComponent.h"

	CollisionComponent::CollisionComponent(unsigned id, ShapeType shape) 
		: _id(id), _shape(shape)
	{

	}

	CollisionComponent::~CollisionComponent() {

	}

	unsigned CollisionComponent::getId() const {
		return _id;
	}