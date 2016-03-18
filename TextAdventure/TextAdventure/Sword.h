/*
	Author:			Jack Vine
	Date Created:	16/3/2016
	Brief:			A basic sword. A type of weapon.
*/

#pragma once

#include "Item.h"

class Sword : public Item
{
public:
	Sword();
	virtual ~Sword();

	virtual void Use(Character* target);
};

