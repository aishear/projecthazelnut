#pragma once
#include <string>
#include <map>
#include "stdafx.h"

class TextureManager {
public:

	static enum TextureType {
		TestPlanet,
		EndTurn
	};

	TextureManager();
	sf::Texture* getTexture(TextureType type);

private:
	std::map<std::string, sf::Texture*> _textures;
	static const char* const paths[];
	static const int NUM_IMAGES = 2;
};