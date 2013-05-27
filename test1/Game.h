#pragma once
#include "stdafx.h"
#include "TextureManager.h"
#include "SlotMap.h"
#include "Planet.h"

class Game
{
public:
	static void start();
	static sf::RenderWindow& GetWindow();
	static TextureManager& getTextureManager();
	
	static int getScreenWidth();
	static int getScreenHeight();

private:

	const static int SCREEN_WIDTH = 1024;
	const static int SCREEN_HEIGHT = 768;

	static void gameLoop();
	static void handleEvents();
	static void updateView();

	static sf::RenderWindow _mainWindow;
	static sf::View _view;
	static sf::Clock _clock;

	static TextureManager _textureManager;

	static bool _freeLook;
	static sf::Vector2i _pressPosition;
	static sf::Vector2i _viewOffset;
	static float _zoomLevel;

	static SlotMap<GameObject> _planets;
};