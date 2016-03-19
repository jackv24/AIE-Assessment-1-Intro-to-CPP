/*
	Author:			Jack Vine
	Date Created:	19/3/2016
	Brief:			A potion. Heals the target (usually the player)
*/

#pragma once

#include "Item.h"

class Potion : public Item
{
public:
	Potion();
	virtual ~Potion();

	virtual void Use(Character* target);
};

