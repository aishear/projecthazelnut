#include "stdafx.h"
#include "TextureManager.h"

TextureManager::TextureManager() {
	_t.loadFromFile("D:/Programming/SFML/projects/test1 - Copy/Debug/test.png");
}

sf::Texture& TextureManager::getTestTexture() {
	return _t;
}