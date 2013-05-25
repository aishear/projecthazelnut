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

- User interface
- player object
- projectile object
- game states
- main menu
- in-game menu
- maps - static and procdually generated

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

void Game::handleEvents(){
	sf::Event event;
    while (_mainWindow.pollEvent(event))
    {
        switch (event.type) {
			case sf::Event::Closed:
				_mainWindow.close();
				break;
			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Right) {
					_freeLook = true;
					_pressPosition = sf::Vector2i(_viewOffset.x + event.mouseButton.x, _viewOffset.y + event.mouseButton.y);
				}
				break;
			case sf::Event::MouseButtonReleased:
				if (event.mouseButton.button == sf::Mouse::Right)
					_freeLook = false;
				break;
			case sf::Event::MouseWheelMoved:
				int mouseDelta = event.mouseWheel.delta;
				if (mouseDelta > 0 && _zoomLevel > .5){
					_zoomLevel -= .25;
					float zoom = 1 - (mouseDelta * 0.25);
					_view.zoom(zoom);
				}else if (mouseDelta < 0 && _zoomLevel < 4){
					_zoomLevel += .25;
					float zoom = 1 - (mouseDelta * 0.25);
					_view.zoom(zoom);
				}
				break;
		}
    }
}

void Game::updateView(){
	if (_freeLook) {
		auto mousePosition = sf::Mouse::getPosition(_mainWindow);
		auto dragDistance = (_pressPosition - mousePosition);
		auto delta = _viewOffset - dragDistance;
		_viewOffset = dragDistance;
		_view.move(-delta.x * _zoomLevel, -delta.y * _zoomLevel);
		
	}
}

void Game::gameLoop() {

	//add random planets
	/*
	for (int i = 0; i < 400; i++){
		int x = rand() % 1000;
		int y = rand() % 700;
		_entityManager.addPlanetEntity(sf::Vector2f(x, y), sf::Vector2f(x/100, y/100), 500, 5);
	}
	*/

	_entityManager.addPlanetEntity(sf::Vector2f(500, 400), sf::Vector2f(0, 0), 4000, 60);
	_entityManager.addPlanetEntity(sf::Vector2f(200, 400), sf::Vector2f(0, 130), 100, 5);
	_entityManager.addPlanetEntity(sf::Vector2f(250, 400), sf::Vector2f(0, 0), 100, 5);

	_view.reset(sf::FloatRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));

	while (_mainWindow.isOpen())
    {
		handleEvents();

        _mainWindow.clear();
		
		auto deltaTime = _clock.restart();
		_positionMap.updateGravity();
		_collisionMap.resolveCollisions();
		_positionMap.updateComponents(deltaTime.asSeconds());
		
		updateView();
		_mainWindow.setView(_view);
		_renderMap.drawAll();
		


		//draw ui stuff unaffected by view
		_mainWindow.setView(_mainWindow.getDefaultView());
		//draw ui stuff here

        _mainWindow.display();

		//update title
		/*
		ostringstream ss;
		ss << 1/deltaTime.asSeconds();
		string s1(ss.str());
		ostringstream sss;
		sss << _entityManager.numEntities();
		string s2(sss.str());
		string s("Title " + s1 + "  " + s2);
		GetWindow().setTitle(s); 
		*/
    }

}

sf::RenderWindow Game::_mainWindow;
sf::View Game::_view;
sf::Clock Game::_clock;
EntityManager  Game::_entityManager;
RenderMap  Game::_renderMap;
PositionMap Game::_positionMap;
CollisionMap Game::_collisionMap;
TextureManager Game::_textureManager;

bool Game::_freeLook = false;
sf::Vector2i Game::_pressPosition;
sf::Vector2i Game::_viewOffset;
float Game::_zoomLevel = 1;