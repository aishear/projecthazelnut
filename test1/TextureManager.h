/*
 * Copyright 2013 Andrew Shearer <kb3luf@verizon.net>
 * MIT LICENCE - see MIT-LICENCE.txt
 * This file is part of projectHazelnut, a n-body simulation and game.
 */

#pragma once
#include <string>
#include <map>
#include "stdafx.h"

class TextureManager {
public:

	static enum TextureType {
		TestPlanet,
		EndTurn,
		Ship,
		Bullet
	};

	TextureManager();
	sf::Texture* getTexture(TextureType type);

private:
	std::map<std::string, sf::Texture*> _textures;
	static const char* const paths[];
	static const int NUM_IMAGES = 4;
};
