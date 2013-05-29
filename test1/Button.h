#pragma once
#include "stdafx.h"
#include "IDrawable.h"
#include "ISlotItem.h"

class Button : public IDrawable, public ISlotItem {
public:
	Button(sf::Rect<float> & bound, sf::Sprite & sprite, std::function< void ()> action);
	virtual void draw(sf::RenderWindow & rw);
	bool containsPoint(float x, float y);
	void performAction();
	void setId(SLOTMAP_ID id);
	SLOTMAP_ID getId();
private:
	std::function< void ()> _action;
	sf::Sprite _sprite;
	sf::Rect<float> _bound;
	SLOTMAP_ID _id;
};