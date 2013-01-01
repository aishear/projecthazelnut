#include "stdafx.h"
#include "EntityManager.h"
#include "Game.h"

EntityManager::EntityManager() 
	: _nextId(0)
{

}

EntityManager::~EntityManager() {

}

unsigned EntityManager::getNextId() {
	auto ret = _nextId;
	_usedIds.insert(ret);

	_nextId++;
	return ret;
}

void EntityManager::addPlanetEntity(sf::Vector2f position, sf::Vector2f delta, float mass, float radius) {
	auto id = getNextId();

	sf::Sprite s;
	s.setOrigin(radius, radius);
	s.setPosition(position);
	s.setTexture(Game::getTextureManager().getTestTexture());
	Game::getRenderMap().addRenderComponent(id, s);
	Game::getPositionMap().addPositionComponent(id, position, delta, mass);
}