#pragma once
#include "stdafx.h"

class Component {
public:
	virtual ~Component() {}

protected:
	Component(unsigned id) : _id(id)
	{
	}
	unsigned _id;
};