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
	_nextId++;
	return ret;
}

void EntityManager::addPlanetEntity(sf::Vector2f position, sf::Vector2f delta, float mass, float radius) {
	auto id = getNextId();
	_entityMap.insert(pair<unsigned, EntityType>(id, Planet));

	sf::Sprite s;
	sf::Texture* texture = Game::getTextureManager().getTexture(TextureManager::TestPlanet);
	s.setOrigin(texture->getSize().x / 2.0, texture->getSize().y / 2.0);
	s.setPosition(position);
	s.setTexture(*texture);

	auto size = (radius*2)/s.getTexture()->getSize().x;
	s.setScale(size, size);

	Game::getRenderMap().addRenderComponent(id, s);
	Game::getPositionMap().addPositionComponent(id, position, delta, mass);
	Game::getCollisionMap().addCollisionComponent(id, CollisionComponent::Circle, radius*2, radius*2);
}

void EntityManager::addButton(sf::Rect<float> bound, std::function<void ()> action, sf::Sprite sprite) {
	auto id = getNextId();
	_entityMap.insert(pair<unsigned, EntityType>(id, Button));

	Game::getButtonMap().addButtonComponent(id, action, bound);

	sprite.setPosition(bound.left, bound.top);
	Game::getRenderMap().addRenderComponent(id, sprite);
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