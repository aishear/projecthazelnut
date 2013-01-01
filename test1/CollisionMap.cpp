#include "stdafx.h"
#include "CollisionComponent.h"
#include "CollisionMap.h"

using namespace std;

CollisionMap::CollisionMap() {

}

CollisionMap::~CollisionMap() {

}

CollisionComponent* CollisionMap::getCollisionComponent(unsigned id) {
	return _collisionMap.find(id)->second;
}

void CollisionMap::addCollisionComponent(unsigned id, CollisionComponent::shapeType shape) {
	auto cc = new CollisionComponent(id, shape);
	_collisionMap.insert(pair<unsigned, CollisionComponent*>(id, cc));
}