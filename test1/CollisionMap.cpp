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

void CollisionMap::addCollisionComponent(unsigned id, CollisionComponent::ShapeType shape) {
	auto cc = new CollisionComponent(id, shape);
	_collisionMap.insert(pair<unsigned, CollisionComponent*>(id, cc));
}

void CollisionMap::removeCollisionComponent(unsigned id) {
	auto cc = _collisionMap.find(id)->second;
	delete cc;
	_collisionMap.erase(id);
}

void CollisionMap::resolveCollisions() {
	for_each(begin(_collisionMap), end(_collisionMap), [&](pair<unsigned, CollisionComponent*> i){

		for_each(begin(_collisionMap), end(_collisionMap), [&](pair<unsigned, CollisionComponent*> j){
			if (i != j) {
				auto positionI = Game::getPositionMap().getPositionComponent(i.second->getId());
				auto positionJ = Game::getPositionMap().getPositionComponent(j.second->getId());

				if (isCircleColliding(positionI->getPosition(), 4.5, positionJ->getPosition(), 4.5)) {
					
					if (positionI->getMass() > positionJ->getMass()) {
						resolveCollision(positionI, positionJ);
					}else{
						resolveCollision(positionJ, positionI);
					}
				}

			}
		});
	});

}

bool CollisionMap::isCircleColliding(sf::Vector2f position1, float radius1, sf::Vector2f position2, float radius2) {
	float dx = position2.x - position1.x;
	float dy = position2.y - position1.y;
	float radii = radius1 + radius2;
	
	//check for collisions
	return (( dx * dx )  + ( dy * dy ) < radii * radii);  //both sides have been squared
}

void CollisionMap::resolveCollision(PositionComponent* large, PositionComponent* small) {
	//small object will merge into large body
	
	//add the mass to the larger body and transfer the vector from the smaller to the larger body
	//the ratio of the masses is used to prevent very small objects from efecting large objects too much

	float massRatio = small->getMass() / large->getMass();
	large->setDelta(large->getDelta() + (massRatio * small->getDelta()));
	large->setMass(large->getMass() + small->getMass());
	//large->setRadius(log10(large->getMass()));
	//large->setRadius(sqrt(large->getRadius() * large->getRadius() + small->getRadius() * small->getRadius()));
	

	small->setMass(0); //the small object's mass will be set to 0 so that it can later be detected and removed
}

/*

bool PlanetaryBodyManager::isColliding(PlanetaryBody* x, PlanetaryBody* y) {
	sf::Vector2f position1 = x->getPosition();
	sf::Vector2f position2 = y->getPosition();

	float dx = position2.x - position1.x;
	float dy = position2.y - position1.y;
	float radii = x->getRadius() + y->getRadius();
	
	//check for collisions
	return (( dx * dx )  + ( dy * dy ) < radii * radii);  //both sides have been squared

}

void PlanetaryBodyManager::resolveCollision(PlanetaryBody* large, PlanetaryBody* small) {
	//small object will merge into large body
	
		
	//add the mass to the larger body and transfer the vector from the smaller to the larger body
	//the ratio of the masses is used to prevent very small objects from efecting large objects too much

	float massRatio = small->getMass() / large->getMass();
	large->setVector(large->getVector() + (massRatio * small->getVector()));
	large->setMass(large->getMass() + small->getMass());
	//large->setRadius(log10(large->getMass()));
	large->setRadius(sqrt(large->getRadius() * large->getRadius() + small->getRadius() * small->getRadius()));
	
	small->setMass(0); //the small object's mass will be set to 0 so that it can later be detected and removed
			

}

*/