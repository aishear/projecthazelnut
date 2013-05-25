#include "stdafx.h"
#include "CollisionComponent.h"
#include "CollisionMap.h"
#include "Game.h"
#include "PositionComponent.h"

using namespace std;

CollisionMap::CollisionMap() {

}

CollisionMap::~CollisionMap() {

}

CollisionComponent* CollisionMap::getCollisionComponent(unsigned id) {
	return _collisionMap.find(id)->second;
}

void CollisionMap::addCollisionComponent(unsigned id, CollisionComponent::ShapeType shape, float width, float height) {
	auto cc = new CollisionComponent(id, shape, width, height);
	_collisionMap.insert(pair<unsigned, CollisionComponent*>(id, cc));
}

void CollisionMap::removeCollisionComponent(unsigned id) {
	auto cc = _collisionMap.find(id)->second;
	delete cc;
	_collisionMap.erase(id);
}

void CollisionMap::resolveCollisions() {
	bool collisionDetected = false;
	set<unsigned> removeIds;

	for (auto i = begin(_collisionMap); i != end(_collisionMap); i++) {
		for (auto j = begin(_collisionMap); j != end(_collisionMap); j++) {
			if (i != j) {
				auto positionI = Game::getPositionMap().getPositionComponent(i->second->getId());
				auto positionJ = Game::getPositionMap().getPositionComponent(j->second->getId());
				


				if (isCircleColliding(positionI->getPosition(), i->second->getWidth()/2, positionJ->getPosition(), j->second->getWidth()/2)) {
					collisionDetected = true;

					if (positionI->getMass() > positionJ->getMass()) {
						resolveCollision(positionI, positionJ, i->second, j->second);
						removeIds.insert(positionJ->getId());
					}else{
						resolveCollision(positionJ, positionI, j->second, i->second);
						removeIds.insert(positionI->getId());
					}
				}

			}
		}
	}

	if (collisionDetected) {
		for_each(begin(removeIds), end(removeIds), [=](unsigned id) {
			Game::getEntityManager().removeEntity(id);
		});
	}

}

bool CollisionMap::isCircleColliding(sf::Vector2f position1, float radius1, sf::Vector2f position2, float radius2) {
	float dx = position2.x - position1.x;
	float dy = position2.y - position1.y;
	float radii = radius1 + radius2;
	
	//check for collisions
	return (( dx * dx )  + ( dy * dy ) < radii * radii);  //both sides have been squared
}

void CollisionMap::resolveCollision(PositionComponent* large, PositionComponent* small, CollisionComponent* largeCollision, CollisionComponent* smallCollision) {
	//small object will merge into large body
	
	//add the mass to the larger body and transfer the vector from the smaller to the larger body
	//the ratio of the masses is used to prevent very small objects from efecting large objects too much

	float massRatio = small->getMass() / large->getMass();
	large->setDelta(large->getDelta() + (massRatio * small->getDelta()));
	large->setMass(large->getMass() + small->getMass());

	auto largeRadius = largeCollision->getWidth()/2;
	auto smallRadius = smallCollision->getWidth()/2;

	auto newRadius = sqrt(largeRadius*largeRadius + smallRadius*smallRadius);

	largeCollision->setHeight(newRadius*2);
	largeCollision->setWidth(newRadius*2);

	//stretch graphics
	auto id = large->getId();
	auto width = Game::getTextureManager().getTexture(TextureManager::TestPlanet)->getSize().x;
	Game::getRenderMap().getRenderComponent(id)->changeSize((newRadius*2)/width, (newRadius*2)/width, newRadius);
}
