/*
 * Copyright 2013 Andrew Shearer <kb3luf@verizon.net>
 * MIT LICENCE - see MIT-LICENCE.txt
 * This file is part of projectHazelnut, a n-body simulation and game.
 */

#include "stdafx.h"
#include "Game.h"
#include "TextureManager.h"
#include "Planet.h"
#include "SlotMap.h"
#include "Gravity.h"
#include "Drawer.h"
#include "GameObject.h"
#include "Ship.h"
#include "Collision.h"
#include "Bullet.h"
/*
_______________________________________
---------------TODO LIST---------------
_______________________________________

- User interface
- game states
- main menu
- in-game menu
- maps - static and procdually generated

_______________________________________
-----------------IDEAS-----------------
_______________________________________

gavity field view
-many vectors (drawn as lines) that show gravy field on map
-show how gravity effects shot for a short distance
*/


void Game::start() {

	_mainWindow.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32), "Project Hazelnut");

	_view.reset(sf::FloatRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
	initLevel();
	gameLoop();

	_mainWindow.close();
}

void Game::initLevel() {
	//add planets
	sf::Sprite s;
	s.setTexture(*_textureManager.getTexture(TextureManager::TestPlanet));

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			float size = (rand() % 100) + 10;
			_gBodies.add(new Planet(sf::Vector2f(i * 100, j * 100 + 20*i), sf::Vector2f(0, 0), size, s, size/10));
		}
	}

	//add end turn button
	sf::Sprite endTurn;
	endTurn.setTexture(*_textureManager.getTexture(TextureManager::EndTurn));
	_buttons.add(new Button(sf::Rect<float>(5, 5, 100, 60), endTurn, [](){
		if (_simulationState == Game::Plan) {
			_simulationState = Game::Simulate;
			_turnTimer.restart();
		}
	}));

	//add ship
	sf::Sprite ship;
	ship.setTexture(*_textureManager.getTexture(TextureManager::Ship));
	Ship* playerShip = new Ship(sf::Vector2f(-100, -100), sf::Vector2f(0,0), 100, ship, 20);
	addShip(playerShip);
	_selectedShip = playerShip;
	
	//test bullet
	sf::Sprite bullet;
	bullet.setTexture(*_textureManager.getTexture(TextureManager::Bullet));
	_gBodies.add(new Bullet(sf::Vector2f(-67, -100), sf::Vector2f(50,0), 10, bullet, 2));
}

sf::RenderWindow& Game::GetWindow() {
	return Game::_mainWindow;
}

int Game::getScreenWidth() {
	return Game::_mainWindow.getSize().x;
}

int Game::getScreenHeight() {
	return Game::_mainWindow.getSize().y;
}

TextureManager& Game::getTextureManager() {
	return _textureManager;
}

void Game::handleEvents() {
	sf::Event event;
    while (_mainWindow.pollEvent(event))
    {
        switch (event.type) {
			case sf::Event::Closed:
				_mainWindow.close();
				break;
			
			case sf::Event::KeyPressed:
				switch(event.key.code) {
					case sf::Keyboard::Space:
						if (_selectedShip) _selectedShip->fire(rand(), 100);
						break;
					case sf::Keyboard::Up:
						_selectedShip->setThrust(3.1415 / 2, 30);
						break;
					case sf::Keyboard::Down:
						_selectedShip->setThrust((3 * 3.1415) / 2, 30);
						break;
					case sf::Keyboard::Left:
						_selectedShip->setThrust(3.1415, 30);
						break;
					case sf::Keyboard::Right:
						_selectedShip->setThrust(0, 30);
						break;
					default:
						break;
				}
				break;

			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Right) {
					_freeLook = true;
					_pressPosition = sf::Vector2i(_viewOffset.x + event.mouseButton.x, _viewOffset.y + event.mouseButton.y);
				} else if (event.mouseButton.button == sf::Mouse::Left) {
					handleLeftClick(event.mouseButton.x, event.mouseButton.y);
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

void Game::handleLeftClick(int x, int y) {
	std::for_each(_buttons.begin(), _buttons.end(), [=](Button* i){
		if (i->containsPoint((float)x, (float)y))
			i->performAction();
	});
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
	while (_mainWindow.isOpen())
    {
		handleEvents();

        _mainWindow.clear();
		
		auto deltaTime = _clock.restart();
		updateView();
		_mainWindow.setView(_view);

		Drawer::updateObjects(_gBodies.begin(), _gBodies.end());

		Drawer::drawAll(_gBodies.begin(), _gBodies.end(), _gBodies.size(), _mainWindow);

		if (_simulationState == Game::Simulate) {
			Gravity::updateDeltas(_gBodies.getAll(), deltaTime.asSeconds());
			Gravity::updatePositions(_gBodies.begin(), _gBodies.end(), deltaTime.asSeconds());

			Collision::detectCollisions(_gBodies.begin(), _gBodies.end());
			Collision::resolveCollisions();

			//check to see if turn is finished
			if (_turnTimer.getElapsedTime().asSeconds() > TURN_TIME_LIMIT) {
				_simulationState = Game::Plan;
			}
			//check to see if trail vertex should be added to gBodies
			if (_gBodyTrailTimer.getElapsedTime().asSeconds() > TRAIL_TIME) {
				_gBodyTrailTimer.restart();
				std::for_each(_gBodies.begin(), _gBodies.end(), [](GameObject* i){
					i->addTrailPoint();
				});
			}
		} else {
			//draw ui stuff unaffected by view
			_mainWindow.setView(_mainWindow.getDefaultView());
			//draw ui stuff here
			std::for_each(_buttons.begin(), _buttons.end(), [](Button* i){
				i->draw(_mainWindow);
			});
		}
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

void Game::removeGBody(SLOTMAP_ID id) {
	_gBodies.remove(id);
}

void Game::removeShip(SLOTMAP_ID id) {
	_ships.erase(id);
}

SLOTMAP_ID Game::addPlanet(Planet* p) {
	return _gBodies.add(p);
}

SLOTMAP_ID Game::addShip(Ship* s) {
	auto id = _gBodies.add(s);
	_ships.insert(std::pair<SLOTMAP_ID, Ship*>(id, s));
	return id;
}

SLOTMAP_ID Game::addBullet(Bullet* b) {
	return _gBodies.add(b);
}

sf::RenderWindow Game::_mainWindow;
sf::View Game::_view;
sf::Clock Game::_clock;

sf::Clock Game::_turnTimer;
sf::Clock Game::_gBodyTrailTimer;
const float Game::TURN_TIME_LIMIT = 300;
const float Game::TRAIL_TIME = 0.3;

TextureManager Game::_textureManager;

bool Game::_freeLook = false;
sf::Vector2i Game::_pressPosition;
sf::Vector2i Game::_viewOffset;
float Game::_zoomLevel = 1;

Game::State Game::_simulationState = Game::Plan;
Ship* Game::_selectedShip;

SlotMap<GameObject*> Game::_gBodies;
std::map<SLOTMAP_ID, Ship*> Game::_ships;

SlotMap<Button*> Game::_buttons;
