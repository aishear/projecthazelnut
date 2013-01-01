#pragma once
#include "stdafx.h"
#include "RenderComponent.h"

using namespace std;

class RenderMap {
public:

	RenderMap();
	~RenderMap();

	RenderComponent* getRenderComponent(unsigned id);
	void addRenderComponent(unsigned id, sf::Sprite& sprite);
	void drawAll();

private:
	

	map<unsigned, RenderComponent*> _renderMap;
};