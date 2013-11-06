/*
 * Copyright 2013 Andrew Shearer <kb3luf@verizon.net>
 * MIT LICENCE - see MIT-LICENCE.txt
 * This file is part of projectHazelnut, a n-body simulation and game.
 */

#include "stdafx.h"
#include "TextureManager.h"

TextureManager::TextureManager() {
	for (int i = 0; i < NUM_IMAGES; i++) {
		sf::Texture* t = new sf::Texture();
		t->loadFromFile(paths[i]);
		_textures[paths[i]] = t;
	}
}

sf::Texture* TextureManager::getTexture(TextureType type) {
	return _textures[paths[type]];
}

const char* const TextureManager::paths[] = {
	"D:/Programming/SFML/projects/projectHazelnut/images/test.png",
	"D:/Programming/SFML/projects/projectHazelnut/images/endTurn.png",
	"D:/Programming/SFML/projects/projectHazelnut/images/ship.png",
	"D:/Programming/SFML/projects/projectHazelnut/images/bullet.png"
};
