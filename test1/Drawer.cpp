#pragma once
#include "stdafx.h"
#include "Drawer.h"
#include "GameObject.h"

void Drawer::drawAll(const std::vector<GameObject*>::iterator& begin, const std::vector<GameObject*>::iterator& end, sf::RenderWindow& rw) {
	std::for_each(begin, end, [&rw](GameObject* i){
		i->draw(rw);
	});
}

void Drawer::updateGraphics(const std::vector<GameObject*>::iterator& begin, const std::vector<GameObject*>::iterator& end) {
	std::for_each(begin, end, [](GameObject* i){
			i->updateSprite();
	});
}