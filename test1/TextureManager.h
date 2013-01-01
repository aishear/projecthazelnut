#pragma once
#include "stdafx.h"

class TextureManager {
public:
	TextureManager();
	sf::Texture& getTestTexture();
private:
	sf::Texture _t;
};