#pragma once
#include "stdafx.h"
#include "ButtonComponent.h"

using namespace std;

class ButtonMap {
public:

	ButtonMap();
	~ButtonMap();

	ButtonComponent* getButtonComponent(unsigned id);
	void addButtonComponent(unsigned id, std::function<void ()> action, sf::Rect<float> bound);
	void removeButtonComponent(unsigned id);

private:
	
	map<unsigned, ButtonComponent*> _buttonMap;
};