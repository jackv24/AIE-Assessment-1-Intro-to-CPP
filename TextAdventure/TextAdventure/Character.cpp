#include "Character.h"

Character::Character()
{
	m_name = "Character";

	m_health = 0;
}

Character::~Character()
{
	if (!m_inventory.empty())
	{
		//Delete item pointers
		for (Item* item : m_inventory)
			delete item;
		//Then clear vector
		m_inventory.clear();
	}
}

String Character::GetName()
{
	return m_name;
}

void Character::Action()
{
	//Nothing happens, because a basic character can do nothing
	std::cout << m_name << " did nothing." << std::endl;
}

void Character::DisplayInventory()
{
	//If the inventory is empty, indicate this
	if (m_inventory.empty())
		std::cout << "\nInventory is empty!" << std::endl;
	//Otherwise list inventory items
	else
	{
		std::cout << "\nInventory:" << std::endl;

		for (Item* item : m_inventory)
		{
			std::cout << "\t" << item->GetName() << std::endl;
		}
	}

	//End with a newline (for nice formatting purposes)
	std::cout << std::endl;
}