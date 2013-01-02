#include "stdafx.h"
#include "CollisionComponent.h"

CollisionComponent::CollisionComponent(unsigned id, ShapeType shape, float width, float height) 
	: _id(id), _shape(shape), _width(width), _height(height)
{

}

CollisionComponent::~CollisionComponent() {

}

void CollisionComponent::setWidth(float width) {
	_width = width;
}

void CollisionComponent::setHeight(float height) {
	_height = height;
}

unsigned CollisionComponent::getId() const {
	return _id;
}

float CollisionComponent::getWidth() const {
	return _width;
}

float CollisionComponent::getHeight() const {
	return _height;
}