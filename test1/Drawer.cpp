#pragma once
#include "stdafx.h"
#include "Drawer.h"
#include "GameObject.h"

void Drawer::drawAll(const std::vector<GameObject*>::iterator& begin, const std::vector<GameObject*>::iterator& end, int numObjects, sf::RenderWindow& rw) {
	_trails.resize(GameObject::TRAIL_LENGTH * numObjects);
	
	std::for_each(begin, end, [](GameObject* i){
		sf::Color color = i->getTrailColor();
		std::for_each(i->getTrail()->begin(), i->getTrail()->end(), [&color](sf::Vector2f& point) {
			Drawer::_trails.append(sf::Vertex(point, color));
		});
	});
	
	rw.draw(_trails);

	std::for_each(begin, end, [&rw](GameObject* i){
		i->draw(rw);
	});
}

void Drawer::updateObjects(const std::vector<GameObject*>::iterator& begin, const std::vector<GameObject*>::iterator& end) {
	std::for_each(begin, end, [](GameObject* i){
			i->updateSprite();
	});
}

sf::VertexArray Drawer::_trails(sf::Lines);