#include "Player.h"
#include "Helper.h"
#include "Windows.h"
#include <time.h>

Player::Player()
{
	m_name = "You";
	m_health = m_maxHealth = 100;
}

Player::~Player()
{

}

void Player::Action(std::vector<Character*> characters)
{
	//Console handle to change colours
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	bool running = true;
	String command;

	while (running)
	{
		//Make sure the input stream is cleared after the last iteration
		ClearInput();

		//Since this is a monster room, set the text colour to be red (dim for commands)
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);

		std::cout << "\nEnter a command: ";
		std::cin >> command;
		std::cout << std::endl << std::endl;

		//Light red for descriptions
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);

		if (command.ToLowercase() == "attack")
		{
			unsigned int enemyNumber;

			std::cin >> enemyNumber;

			//Make sure the chosen enemy index is within bounds
			if (enemyNumber >= characters.size())
			{
				std::cout << "That enemy does not exist!\n";
				continue;
			}

			Character* target = characters[enemyNumber];

			if (target->IsAlive())
			{
				Attack(target);
			}
			else
			{
				std::cout << m_name << " attack " << target->GetName() << "'s lifeless corpse.\n";
			}

			running = false;
		}
		else if (command.ToLowercase() == "inventory")
		{
			DisplayInventory();
		}
		else if (command.ToLowercase() == "use")
		{
			String itemName;
			std::cin >> itemName;

			//Pointer to item to use (stays nullptr if item not found)
			Item* item = nullptr;
			//Used to remove item later
			int itemIndex = -1;

			//Iterate through inventory to find item
			for (unsigned int i = 0; i < m_inventory.size(); i++)
			{
				if (m_inventory[i]->GetName().ToLowercase() == itemName.ToLowercase())
				{
					//Cant use a weapon on self
					if (m_inventory[i]->GetType() != Item::Type::WEAPON)
						item = m_inventory[i];

					itemIndex = i;

					//If item is found, stop searching
					break;
				}
			}

			//If no item was found...
			if (item == nullptr)
			{
				std::cout << "You don't own a " << itemName << " item!\n";

				//...return to enter a command
				continue;
			}
			else
			{
				std::cout << "You used " << itemName << ".\n\n";

				//Use item on self
				item->Use(characters[0]);

				//If the item is consumable, remove it
				if (item->GetType() == Item::Type::CONSUMABLE)
				{
					//Clear memory
					delete item;
					//Remove from inventory
					m_inventory.erase(m_inventory.begin() + itemIndex);
				}

				//Using an item also uses a turn
				running = false;
			}
		}
		else if (command.ToLowercase() == "help")
		{
			std::cout << "Commands:\n"
				<< " - attack <enemy number>\n"
				<< " - inventory\n"
				<< " - use <item name>\n";
		}
		else
		{
			std::cout << "Invalid command." << std::endl;
		}
	}
}

void Player::Attack(Character* target)
{
	//continue to loop until an attack has been performed
	while (true)
	{
		String command;
		std::cout << "Attack to perform: ";
		std::cin >> command;
		std::cout << std::endl;

		if (command.ToLowercase() == "help")
		{
			std::cout << "Your attacks are:\n"
				<< " - punch\n"
				<< " - kick\n\n"
				
				<< " - use <weapon name>\n\n";

			continue;
		}
		else if (command.ToLowercase() == "punch")
		{
			std::cout << "You punched yourself.\n\n";

			//Damage between 20 and 30
			target->RemoveHealth(rand() % 10 + 20);
		}
		else if (command.ToLowercase() == "kick")
		{
			std::cout << m_name << " kicked " << target->GetName() << ".\n\n";

			//Damage between 10 and 40
			target->RemoveHealth(rand() % 30 + 10);
		}
		else if (command.ToLowercase() == "use")
		{
			String weaponName;
			std::cin >> weaponName;

			//Pointer to item to use (stays nullptr if item not found)
			Item* weapon = nullptr;

			//Iterate through inventory to find item
			for (Item* itemToUse : m_inventory)
			{
				if (itemToUse->GetName().ToLowercase() == weaponName.ToLowercase())
				{
					//Make sure the item is a weapon
					if(itemToUse->GetType() == Item::Type::WEAPON)
						weapon = itemToUse;

					//If item is found, stop searching
					break;
				}
			}

			//If no item was found...
			if (weapon == nullptr)
			{
				std::cout << "You don't own a " << weaponName << " weapon!\n\n";

				//...return to enter a command
				continue;
			}
			else
			{
				std::cout << "You attack " << target->GetName() << " with " << weapon->GetName() << ".\n\n";
				
				//Use item (apply damage, etc)
				weapon->Use(target);
			}
		}
		else //If in invalid attack was entered...
		{
			std::cout << "You can't use that attack.\n\n";

			//...ask again for another attack
			continue;
		}

		//If an attack was entered successfully, break the loop
		break;
	}
}