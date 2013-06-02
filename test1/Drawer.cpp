#pragma once
#include "stdafx.h"
#include "Drawer.h"
#include "GameObject.h"

void Drawer::drawAll(const std::vector<GameObject*>::iterator& begin, const std::vector<GameObject*>::iterator& end, int numObjects, sf::RenderWindow& rw) {
	sf::VertexArray trails(sf::Lines, GameObject::TRAIL_LENGTH * numObjects);
	
	std::for_each(begin, end, [&trails](GameObject* i){
		sf::VertexArray& t = trails;
		sf::Color color = i->getTrailColor();
		std::for_each(i->getTrail()->begin(), i->getTrail()->end(), [&t, &color](sf::Vector2f& point) {
			t.append(point);
			t[t.getVertexCount() - 1].color = color;
		});
	});
	
	rw.draw(trails);

	std::for_each(begin, end, [&rw](GameObject* i){
		i->draw(rw);
	});
}

void Drawer::updateGraphics(const std::vector<GameObject*>::iterator& begin, const std::vector<GameObject*>::iterator& end) {
	std::for_each(begin, end, [](GameObject* i){
			i->updateSprite();
	});
}