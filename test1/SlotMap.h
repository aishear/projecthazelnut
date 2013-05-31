#pragma once
#include "stdafx.h"

typedef int SLOTMAP_ID;

template <class T>
class SlotMap {
public:
	SlotMap() {
		_size = 0;
		addSlots(100);
	}

	T get(SLOTMAP_ID id) {
		int index = _slots[id];
		return _objects[index];
	}

	SLOTMAP_ID add(T object) {	
		_size++;

		if (_freeStack.empty()) {
			addSlots(100);	
		}
		int id = _freeStack.top();
		_freeStack.pop();
		_slots[id] = _size - 1;

		object->setId(id);
		_objects.push_back(object);

		return id;
	}

	void remove(SLOTMAP_ID id) {
		int index = _slots[id];
		_slots[id] = -1;
		_freeStack.push(id);
		int backId = _objects.back()->getId();
		_slots[backId] = index;
		std::swap(_objects[index], _objects.back());
		delete _objects[_size - 1];
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

	int size() {
		return _size;
	}

private:

	void addSlots(int numSlots) {
		int startingIndex = _slots.size();
		for (int i = 0; i < numSlots; i++) {
			_slots.push_back(-1);
			_freeStack.push(startingIndex + i);
		}
	}

	std::vector<T> _objects;
	std::vector<int> _slots;
	std::stack<int> _freeStack;
	int _size;
};
