#include "stdafx.h"
#include "Game.h"
#include "EntityManager.h"
#include "RenderMap.h"
#include "PositionMap.h"
#include "CollisionMap.h"
#include "TextureManager.h"
#include <sstream>
#include <cstdlib>

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

	for (int i = 0; i < 30; i++){
		int x = rand() % 1000;
		int y = rand() % 700;
		_entityManager.addPlanetEntity(sf::Vector2f(x, y), sf::Vector2f(x/100, y/100), 100, 10);
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

		//update title
		ostringstream ss;
		ss << 1/deltaTime.asSeconds();
		string s1(ss.str());
		ostringstream sss;
		sss << _entityManager.numEntities();
		string s2(sss.str());
		string s("Title " + s1 + "  " + s2);
		GetWindow().setTitle(s); 
    }

}

sf::RenderWindow Game::_mainWindow;
sf::Clock Game::_clock;
EntityManager  Game::_entityManager;
RenderMap  Game::_renderMap;
PositionMap Game::_positionMap;
CollisionMap Game::_collisionMap;
TextureManager Game::_textureManager;