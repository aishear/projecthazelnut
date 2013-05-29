#include "stdafx.h"
#include "Game.h"
#include "TextureManager.h"
#include "Planet.h"
#include "SlotMap.h"
#include "Gravity.h"
#include "Drawer.h"
#include "GameObject.h"

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

	_view.reset(sf::FloatRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));

	gameLoop();

	_mainWindow.close();
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

void Game::handleEvents() {
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
	std::for_each(_buttons.begin(), _buttons.end(), [=](Button & i){
		if (i.containsPoint((float)x, (float)y))
			i.performAction();
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
	
	sf::Sprite s;
	s.setTexture(*_textureManager.getTexture(TextureManager::TestPlanet));
	
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 10; j++) {
			auto p = Planet(sf::Vector2f(i * 50, j * 50 + 2*i), sf::Vector2f(0,0), 100, s, 10);
			auto id = _planets.add(p);
			p.setId(id);
		}
	}
	for (int i = 0; i < 100; i++) {
		_planets.get(99)->setPosition(sf::Vector2f(1000, i * 50));
	}

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	sf::Sprite endTurn;
	endTurn.setTexture(*_textureManager.getTexture(TextureManager::EndTurn));
	_buttons.add(Button(sf::Rect<float>(5, 5, 100, 60), endTurn, [](){
		if (_simulationState == Game::Simulate) {
			_simulationState = Game::Plan;
		} else {
			_simulationState = Game::Simulate;
		}
	}));

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	while (_mainWindow.isOpen())
    {
		handleEvents();

        _mainWindow.clear();
		
		auto deltaTime = _clock.restart();
		updateView();
		_mainWindow.setView(_view);

		Drawer::updateGraphics(_planets.begin(), _planets.end());
		Drawer::drawAll(_planets.begin(), _planets.end(), _mainWindow);
		if (_simulationState == Game::Simulate) {
			Gravity::updateDeltas(_planets.getAll());
			Gravity::updatePositions(_planets.begin(), _planets.end(), deltaTime.asSeconds());
		}
		//draw ui stuff unaffected by view
		_mainWindow.setView(_mainWindow.getDefaultView());
		//draw ui stuff here
		std::for_each(_buttons.begin(), _buttons.end(), [](Button & i){
			i.draw(_mainWindow);
		});

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

TextureManager Game::_textureManager;

bool Game::_freeLook = false;
sf::Vector2i Game::_pressPosition;
sf::Vector2i Game::_viewOffset;
float Game::_zoomLevel = 1;

Game::State Game::_simulationState = Game::Plan;

SlotMap<GameObject> Game::_planets;

SlotMap<Button> Game::_buttons;