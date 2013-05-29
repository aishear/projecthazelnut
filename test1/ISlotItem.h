#pragma once
#include "stdafx.h"
#include "SlotMap.h"

class ISlotItem {
public:
	~ISlotItem() {}

	virtual void setId(SLOTMAP_ID id) = 0;
	virtual SLOTMAP_ID getId() = 0;
};