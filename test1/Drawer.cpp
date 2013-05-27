#pragma once
#include "stdafx.h"
#include "Drawer.h"
#include "GameObject.h"

void Drawer::drawAll(const std::vector<GameObject>::const_iterator& begin, const std::vector<GameObject>::const_iterator& end, sf::RenderWindow& rw) {
	std::for_each(begin, end, [&](GameObject i){
		i.draw(rw);
	});
}