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

int Character::GetHealth()
{
	return m_health;
}

void Character::RemoveHealth(int amount)
{
	if (IsAlive())
	{
		std::cout << m_name << " took " << amount << " damage.\n\n";
		m_health -= amount;

		//If the health falls below zero
		if (m_health <= 0)
		{
			//Clamp health at zero
			m_health = 0;
			//Show that the character has died
			std::cout << m_name << " died!\n\n";
		}
	}
	else
		std::cout << m_name << " is already dead!\n\n";
}

bool Character::IsAlive()
{
	//If the health is less than or equal to 0, the character is dead
	return ((m_health > 0) ? true : false);
}

void Character::Action(std::vector<Character*> characters)
{
	//Nothing happens, because a basic character can do nothing
	std::cout << m_name << " did nothing." << std::endl;
}

void Character::DisplayInventory()
{
	//If the inventory is empty, indicate this
	if (m_inventory.empty())
		std::cout << "Inventory is empty!";
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