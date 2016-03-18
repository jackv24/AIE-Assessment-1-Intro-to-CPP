/*
	Author:			Jack Vine
	Date Created:	8/3/2016
	Brief:			A subclass of room. Holds treasure which can be picked up by the player.
*/

#pragma once

#include <vector>
#include "Room.h"
#include "Item.h"

class TreasureRoom : public Room
{
public:
	TreasureRoom();
	virtual ~TreasureRoom();

	virtual void Update(Character* player);

private:
	std::vector<Item*> m_items;

	//Prints out a list of all items in the room
	void ListItems();
};

