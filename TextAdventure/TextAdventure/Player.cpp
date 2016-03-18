#include "Player.h"
#include "Helper.h"
#include "Windows.h"
#include <time.h>

Player::Player()
{
	m_name = "You";
	m_health = 100;

	//Rand initialised to prevent reinitialisation every action
	srand(time(NULL));
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
			//Initialise enemy index out of bounds
			int enemyNumber = -1;

			std::cin >> enemyNumber;

			//Make sure the chosen enemy index is within bounds
			while (enemyNumber < 0 || enemyNumber >= characters.size())
			{
				std::cout << "That enemy does not exist!\nEnemy to attack: ";

				std::cin >> enemyNumber;
				std::cout << std::endl;
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
		else if (command.ToLowercase() == "help")
		{
			std::cout << "Commands:\n"
				<< " - attack <enemy number>\n"
				<< " - inventory\n";
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
			std::cout << m_name << " punched " << target->GetName() << ".\n\n";

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
			String itemName;
			std::cin >> itemName;

			//Pointer to item to use (stays nullptr if item not found)
			Item* item = nullptr;

			//Iterate through inventory to find item
			for (Item* itemToUse : m_inventory)
			{
				if (itemToUse->GetName().ToLowercase() == itemName.ToLowercase())
				{
					item = itemToUse;

					//If item is found, stop searching
					break;
				}
			}

			//If no item was found...
			if (item == nullptr)
			{
				std::cout << "You don't own a " << itemName << "!\n\n";

				//...return to enter a command
				continue;
			}
			else
			{
				std::cout << "You attack " << target->GetName() << " with " << item->GetName() << ".\n\n";
				
				//Use item (apply damage, etc)
				item->Use(target);
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