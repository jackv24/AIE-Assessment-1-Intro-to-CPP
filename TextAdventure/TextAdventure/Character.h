/*
	Author:			Jack Vine
	Date Created:	8/3/2016
	Brief:			The character base class. The class from which players and monsters derive.
*/

#pragma once

#include <vector>
#include "String.h"
#include "Item.h"

//Forward declaration resolves circular dependancy problem (Item #includes character)
class Item;

class Character
{
public:
	Character();
	virtual ~Character();

	String GetName();
	int GetHealth();

	void RemoveHealth(int amount);
	void AddHealth(int amount);
	bool IsAlive();

	//virtual action function is called on subclasses if they implement the function
	virtual void Action(std::vector<Character*> characters);

	//Displays the inventory of this character
	void DisplayInventory();
	//Add item to inventory
	void Pickup(Item* item);

protected:
	String m_name;
	int m_health;
	int m_maxHealth;

	std::vector<Item*> m_inventory;
};

