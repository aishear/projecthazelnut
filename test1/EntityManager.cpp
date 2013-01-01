#include "stdafx.h"
#include "EntityManager.h"
#include "Game.h"

using namespace std;

EntityManager::EntityManager() 
	: _nextId(0)
{

}

EntityManager::~EntityManager() {

}

unsigned EntityManager::getNextId() {
	auto ret = _nextId;
	_nextId++;
	return ret;
}

void EntityManager::addPlanetEntity(sf::Vector2f position, sf::Vector2f delta, float mass, float radius) {
	auto id = getNextId();
	_entityMap.insert(pair<unsigned, EntityType>(id, Planet));

	sf::Sprite s;
	s.setOrigin(radius, radius);
	s.setPosition(position);
	s.setTexture(Game::getTextureManager().getTestTexture());
	Game::getRenderMap().addRenderComponent(id, s);
	Game::getPositionMap().addPositionComponent(id, position, delta, mass);
	Game::getCollisionMap().addCollisionComponent(id, CollisionComponent::Circle);
}

void  EntityManager::removeEntity(unsigned id) {
	auto type = _entityMap.find(id)->second;
	switch(type) {
		case Planet:
			_entityMap.erase(id);
			Game::getCollisionMap().removeCollisionComponent(id);
			Game::getPositionMap().removePositionComponent(id);
			Game::getRenderMap().removeRenderComponent(id);
			break;

	}
}

int EntityManager::numEntities() {
	return _entityMap.size();
}