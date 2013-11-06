/*
 * Copyright 2013 Andrew Shearer <kb3luf@verizon.net>
 * MIT LICENCE - see MIT-LICENCE.txt
 * This file is part of projectHazelnut, a n-body simulation and game.
 */

#pragma once
#include "stdafx.h"
#include "GameObjectFactory.h"
#include "Bullet.h"
#include "GameObject.h"
#include "Game.h"
#include "TextureManager.h"

Bullet* GameObjectFactory::createBullet(sf::Vector2f position, sf::Vector2f initialDelta, float mass, float radius) {
	sf::Sprite bulletSprite;
	bulletSprite.setTexture(*Game::getTextureManager().getTexture(TextureManager::Bullet));
	return new Bullet(position, initialDelta, mass, bulletSprite, radius);
}
