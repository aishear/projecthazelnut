#pragma once
#include "stdafx.h"
#include "EntityManager.h"
#include "RenderMap.h"
#include "TextureManager.h"
#include "PositionMap.h"

class Game
{
public:
	static void start();
	static sf::RenderWindow& GetWindow();
	static RenderMap& getRenderMap();
	static PositionMap& getPositionMap();
	static TextureManager& getTextureManager();

	static int getScreenWidth();
	static int getScreenHeight();

private:

	const static int SCREEN_WIDTH = 1024;
	const static int SCREEN_HEIGHT = 768;

	static void gameLoop();

	static sf::RenderWindow _mainWindow;
	static sf::Clock _clock;
	static EntityManager _entityManager;
	static RenderMap _renderMap;
	static PositionMap _positionMap;
	static TextureManager _textureManager;
};