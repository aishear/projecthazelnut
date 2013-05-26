#pragma once
#include "stdafx.h"
#include "RenderComponent.h"
#include "ComponentMap.h"

using namespace std;

class RenderMap : public ComponentMap {
public:

	RenderMap();
	virtual ~RenderMap();


	sf::Sprite& getSprite(unsigned id);
	void add(unsigned id, sf::Sprite& sprite);


	void drawAll();

};