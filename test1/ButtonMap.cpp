#include "stdafx.h"
#include "ButtonMap.h"
#include "ButtonComponent.h"

ButtonMap::ButtonMap() {

}

ButtonMap::~ButtonMap() {

}

ButtonComponent* ButtonMap::getButtonComponent(unsigned id) {
	return _buttonMap.find(id)->second;
}

void ButtonMap::addButtonComponent(unsigned id, std::function<void ()> action, sf::Rect<float> bound) {
	auto bc = new ButtonComponent(id, action, bound);
	_buttonMap.insert(pair<unsigned, ButtonComponent*>(id, bc));
}

void ButtonMap::removeButtonComponent(unsigned id) {
	auto rc = _buttonMap.find(id)->second;
	delete rc;
	_buttonMap.erase(id);
}