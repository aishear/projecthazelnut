#include "stdafx.h"
#include "Game.h"
#include "EntityManager.h"
#include "RenderMap.h"
#include "PositionMap.h"
#include "CollisionMap.h"
#include "TextureManager.h"


/*
_______________________________________
---------------TODO LIST---------------
_______________________________________

1. Pan and zoom
2. User interface
3. player object
4. projectile object
5. game states
6. main menu
7. in-game menu
8. maps - static and procdually generated

_______________________________________
-----------------IDEAS-----------------
_______________________________________

gavity field view
-many vectors (drawn as lines) that show gravy field on map
-dotted line trails for objects

*/


void Game::start() {

	_mainWindow.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32), "Title");

	gameLoop();

	_mainWindow.close();
}

sf::RenderWindow& Game::GetWindow() {
	return Game::_mainWindow;
}

RenderMap& Game::getRenderMap() {
	return Game::_renderMap;
}

PositionMap& Game::getPositionMap() {
	return _positionMap;
}

CollisionMap& Game::getCollisionMap() {
	return _collisionMap;
}

TextureManager& Game::getTextureManager() {
	return _textureManager;
}

EntityManager& Game::getEntityManager() {
	return _entityManager;
}

int Game::getScreenWidth() {
	return Game::_mainWindow.getSize().x;
}

int Game::getScreenHeight() {
	return Game::_mainWindow.getSize().y;
}

void Game::gameLoop() {

	//_entityManager.addPlanetEntity(sf::Vector2f(600, 500), sf::Vector2f(0, 10), 100, 4.5);
	//_entityManager.addPlanetEntity(sf::Vector2f(400,400), sf::Vector2f(0, -10), 100, 4.5);
	//_entityManager.addPlanetEntity(sf::Vector2f(200, 100), sf::Vector2f(), 100, 4.5);
	for (int i = 0; i < Game::SCREEN_WIDTH; i+=200){
		for (int j = 0; j < Game::SCREEN_HEIGHT; j+=200){
			_entityManager.addPlanetEntity(sf::Vector2f(i, j), sf::Vector2f(i/100, j/100), 500, 4.5);
		}
	}

	while (GetWindow().isOpen())
    {
        sf::Event event;
        while (GetWindow().pollEvent(event))
        {
           switch (event.type) {
				case sf::Event::Closed:
					GetWindow().close();
					break;
			}
        }

        GetWindow().clear();

		auto deltaTime = _clock.restart();
		_positionMap.updateGravity();
		_collisionMap.resolveCollisions();
		_positionMap.updateComponents(deltaTime.asSeconds());
		_renderMap.drawAll();
		
        GetWindow().display();
    }

}

sf::RenderWindow Game::_mainWindow;
sf::Clock Game::_clock;
EntityManager  Game::_entityManager;
RenderMap  Game::_renderMap;
PositionMap Game::_positionMap;
CollisionMap Game::_collisionMap;
TextureManager Game::_textureManager;