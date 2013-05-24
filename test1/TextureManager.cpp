#include "stdafx.h"
#include "TextureManager.h"

TextureManager::TextureManager() {
	_t.loadFromFile("D:/Programming/SFML/projects/projectHazelnut/images/test.png");
}

sf::Texture& TextureManager::getTestTexture() {
	return _t;
}