/*
	Author:			Jack Vine
	Date Created:	8/3/2016
	Brief:			A subclass of room. Holds treasure which can be picked up by the player.
*/

#pragma once

#include "Room.h"

class TreasureRoom : public Room
{
public:
	TreasureRoom();
	~TreasureRoom();

	virtual void Update(Character* player);
};

