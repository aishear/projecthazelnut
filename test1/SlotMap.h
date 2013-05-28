#pragma once
#include "stdafx.h"

typedef unsigned SLOTMAP_ID;

template <class T>
class SlotMap {
public:
	SlotMap() {
		_size = 0;
	}

	T* get(SLOTMAP_ID id) {
		return &_objects[id];
	}

	SLOTMAP_ID add(T object) {
		_objects.push_back(object);
		_size++;
		return _size - 1;
	}

	void remove(SLOTMAP_ID id) {
		std::swap(_objects[id], objects.back());
		_objects.pop_back();
		_size--;
	}

	std::vector<T>& getAll() {
		return _objects;
	}

	typename const std::vector<T>::iterator begin() {
		return _objects.begin();
	}

	typename const std::vector<T>::iterator end() {
		return _objects.end();
	}

private:
	std::vector<T> _objects;
	int _size;
};
