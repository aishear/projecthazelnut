#pragma once
#include "stdafx.h"
#include "EntityManager.h"
#include "RenderMap.h"
#include "PositionMap.h"
#include "CollisionMap.h"
#include "TextureManager.h"

class Game
{
public:
	static void start();
	static sf::RenderWindow& GetWindow();
	static RenderMap& getRenderMap();
	static PositionMap& getPositionMap();
	static CollisionMap& getCollisionMap();
	static TextureManager& getTextureManager();
	static EntityManager& getEntityManager();

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
	static CollisionMap _collisionMap;
	static TextureManager _textureManager;
};