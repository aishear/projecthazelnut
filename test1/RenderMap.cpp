/*
 * Copyright 2013 Andrew Shearer <kb3luf@verizon.net>
 * MIT LICENCE - see MIT-LICENCE.txt
 * This file is part of projectHazelnut, a n-body simulation and game.
 */

#include "stdafx.h"
#include "RenderMap.h"
#include "RenderComponent.h"
#include "Game.h"

using namespace std;

RenderMap::RenderMap() {

}

RenderMap::~RenderMap() {

}

void RenderMap::add(unsigned id, sf::Sprite& sprite) {
	ComponentMap::add(id, new RenderComponent(id, sprite));
}

void RenderMap::drawAll() {

	//sf::RenderWindow& window = Game::GetWindow();
	//for_each(begin(_componentMap), end(_componentMap), [&](pair<unsigned, Component*> i){
	//	RenderComponent* rc = (RenderComponent*)i.second;
	//	rc->draw(window);
	//});
}
