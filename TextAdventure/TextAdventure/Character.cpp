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
	std::cout << m_name << " did nothing." << std::endl;
}

void Character::DisplayInventory()
{
	if (m_inventory.empty())
		std::cout << "\nInventory is empty!" << std::endl;
	else
	{
		std::cout << "\nInventory:" << std::endl;

		for (Item* item : m_inventory)
		{
			std::cout << "\t" << item->GetName() << std::endl;
		}
	}

	std::cout << std::endl;
}