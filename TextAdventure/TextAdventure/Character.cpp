#include "Character.h"

Character::Character()
{
	m_name = "Character";

	m_health = m_maxHealth = 0;
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

void Character::AddHealth(int amount)
{
	if (IsAlive())
	{
		//Only heal to max health
		if (amount > m_maxHealth - m_health)
			amount = m_maxHealth - m_health;

		std::cout << m_name << " gained " << amount << "HP.\n\n";
		m_health += amount;
	}
	else
		//Cant heal a dead character
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
		std::cout << "Inventory is empty!" << std::endl;
	//Otherwise list inventory items
	else
	{
		std::cout << "Inventory:" << std::endl;

		for (unsigned int i = 0; i < m_inventory.size(); i++)
		{
			//Display the item name
			std::cout << i + 1 << ". " << m_inventory[i]->GetName();

			//Display the type of item as a prefix
			switch (m_inventory[i]->GetType())
			{
			case Item::Type::BASIC:
				std::cout << " (Item)";
				break;
			case Item::Type::WEAPON:
				std::cout << " (Weapon)";
				break;
			case Item::Type::CONSUMABLE:
				std::cout << " (Consumable)";
				break;
			}

			std::cout << std::endl;
		}
	}
}

void Character::Pickup(Item* item)
{
	m_inventory.push_back(item);
}