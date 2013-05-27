#pragma once
#include "stdafx.h"

typedef unsigned SLOTMAP_ID;

template <class T>
class SlotMap {
public:
	SlotMap() {
		_size = 0;
	}

	T get(SLOTMAP_ID id) {
		return _objects[id];
	}

	void add(T object) {
		_objects.push_back(object);
		_size++;
	}

	void remove(SLOTMAP_ID id) {
		std::swap(_objects[id], objects.back());
		_objects.pop_back();
		_size--;
	}

	std::vector<T>& getAll() {
		return _objects;
	}

	typename const std::vector<T>::const_iterator begin() {
		return _objects.begin();
	}

	typename const std::vector<T>::const_iterator end() {
		return _objects.end();
	}

private:
	std::vector<T> _objects;
	int _size;
};
