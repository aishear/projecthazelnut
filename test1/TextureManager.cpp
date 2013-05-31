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