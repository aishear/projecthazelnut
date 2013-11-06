/*
 * Copyright 2013 Andrew Shearer <kb3luf@verizon.net>
 * MIT LICENCE - see MIT-LICENCE.txt
 * This file is part of projectHazelnut, a n-body simulation and game.
 */

#pragma once
#include "stdafx.h"
#include "SlotMap.h"

class ISlotItem {
public:
	~ISlotItem() {}

	virtual void setId(SLOTMAP_ID id) = 0;
	virtual SLOTMAP_ID getId() = 0;
};
