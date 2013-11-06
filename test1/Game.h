/*
 * Copyright 2013 Andrew Shearer <kb3luf@verizon.net>
 * MIT LICENCE - see MIT-LICENCE.txt
 * This file is part of projectHazelnut, a n-body simulation and game.
 */

#pragma once
#include "stdafx.h"
#include "TextureManager.h"
#include "SlotMap.h"
#include "Planet.h"
#include "Button.h"
#include "Ship.h"
#include "Bullet.h"

class Game
{
public:

	enum State {Simulate, Plan};
	
	static void start();
	static sf::RenderWindow& GetWindow();
	static TextureManager& getTextureManager();
	
	static int getScreenWidth();
	static int getScreenHeight();
	static void removeGBody(SLOTMAP_ID id);
	static void removeShip(SLOTMAP_ID id);

	static SLOTMAP_ID addPlanet(Planet* p);
	static SLOTMAP_ID addShip(Ship* s);
	static SLOTMAP_ID addBullet(Bullet* b);
private:

	const static int SCREEN_WIDTH = 1024;
	const static int SCREEN_HEIGHT = 768;

	const static float TURN_TIME_LIMIT;
	const static float TRAIL_TIME;

	static void initLevel();
	static void gameLoop();
	static void handleEvents();
	static void handleLeftClick(int x, int y);
	static void updateView();
	static sf::RenderWindow _mainWindow;
	static sf::View _view;
	static sf::Clock _clock;

	static TextureManager _textureManager;

	static bool _freeLook;
	static sf::Vector2i _pressPosition;
	static sf::Vector2i _viewOffset;
	static float _zoomLevel;

	static sf::Clock _turnTimer;
	static sf::Clock _gBodyTrailTimer;

	static Game::State _simulationState;
	static Ship* _selectedShip;

	static SlotMap<GameObject*> _gBodies;
	static std::map<SLOTMAP_ID, Ship*> _ships;

	static SlotMap<Button*> _buttons;
};
