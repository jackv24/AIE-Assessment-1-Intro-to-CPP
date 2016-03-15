/*
	Author:			Jack Vine
	Date Created:	8/3/2016
	Brief:			The character base class. The class from which players and monsters derive.
*/

#pragma once

#include <vector>
#include "String.h"
#include "Item.h"

class Character
{
public:
	Character();
	virtual ~Character();

	String GetName();

	virtual void Action();
	void DisplayInventory();

protected:
	String m_name;
	int m_health;

	std::vector<Item*> m_inventory;
};
