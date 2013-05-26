#pragma once
#include "stdafx.h"
#include "Component.h"
#include "ComponentMap.h"

ComponentMap::~ComponentMap() {
	//TODO test this code
	//I am not sure if you can do this
	std::for_each(_componentMap.begin(), _componentMap.end(), [](std::pair<unsigned, Component*> i){
		auto comp = i.second;
		delete comp;
	});
	_componentMap.clear();
}

void ComponentMap::add(unsigned id, Component* c) {
	_componentMap.insert(std::pair<unsigned, Component*>(id, c));
}

Component* ComponentMap::get(unsigned id) {
	return _componentMap[id];
}

void ComponentMap::remove(unsigned id) {
	auto comp = _componentMap[id];
	delete comp;
	_componentMap.erase(id);
}