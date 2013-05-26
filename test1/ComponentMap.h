#pragma once
#include "stdafx.h"
#include "Component.h"

class ComponentMap {
public:
	virtual ~ComponentMap();

	virtual void add(unsigned id, Component* c);

	virtual Component* get(unsigned id);

	virtual void remove(unsigned id);
protected:

	std::map<unsigned, Component*> _componentMap;
};