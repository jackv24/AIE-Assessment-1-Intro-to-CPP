/*
	Author:			Jack Vine
	Date Created:	8/3/2016
	Brief:			The weapon class. A subclass of item, of which other weapons derive from.
*/

#pragma once

#include "Item.h"

class Weapon : public Item
{
public:
	Weapon();
	virtual ~Weapon();

	virtual void Use();

private:
	int m_attack;
	int m_defense;
};

