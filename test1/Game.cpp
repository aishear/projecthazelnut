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
	sf::Sprite s;
	s.setPosition(50,50);
	s.setTexture(*_textureManager.getTexture(TextureManager::TestPlanet));
	Planet p(sf::Vector2f(0,0), sf::Vector2f(0,10), 10, s, 10);
	_planets.add(p);

	sf::Sprite ss;
	ss.setPosition(100,50);
	ss.setTexture(*_textureManager.getTexture(TextureManager::TestPlanet));
	Planet pp(sf::Vector2f(100,0), sf::Vector2f(10,0), 10, ss, 10);
	_planets.add(pp);

	while (_mainWindow.isOpen())
    {
		handleEvents();

        _mainWindow.clear();
		
		auto deltaTime = _clock.restart();
		updateView();
		_mainWindow.setView(_view);

		Drawer::drawAll(_planets.begin(), _planets.end(), _mainWindow);
		Gravity::updateDeltas(_planets.getAll());

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

TextureManager Game::_textureManager;

bool Game::_freeLook = false;
sf::Vector2i Game::_pressPosition;
sf::Vector2i Game::_viewOffset;
float Game::_zoomLevel = 1;

SlotMap<GameObject> Game::_planets;