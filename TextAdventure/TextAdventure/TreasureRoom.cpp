#include "TreasureRoom.h"
#include "Helper.h"

#include "Sword.h"
#include "Potion.h"

TreasureRoom::TreasureRoom()
{
	SetType(Type::TREASURE);
	SetDescription("You encounter a treasure room!");

	//Randomly add items
	if(rand() % 2 == 1)
		m_items.push_back(new Sword());

	int potionCount = rand() % 3;

	for (int i = 0; i < potionCount; i++)
		m_items.push_back(new Potion());
}

TreasureRoom::~TreasureRoom()
{
	if (!m_items.empty())
	{
		//Delete item pointers
		for (unsigned int i = 0; i < m_items.size(); i++)
		{
			delete m_items[i];
		}
		//Then clear vector
		m_items.clear();
	}
}

void TreasureRoom::ListItems()
{
	std::cout << "\nRoom contains:" << std::endl;

	for (unsigned int i = 0; i < m_items.size(); i++)
	{
		std::cout << i + 1 << ". " << m_items[i]->GetName() << std::endl;
	}
	std::cout << std::endl;
}

void TreasureRoom::Update(Character* player)
{
	if(m_items.empty())
		std::cout << "\nThere's no treasure here..." << std::endl;
	else
	{
		//List the items in the room
		ListItems();

		while (true)
		{
			//Make sure input stream is clear before reading in any commands
			ClearInput();

			//Get command
			String command;
			std::cout << "Enter a command: ";
			std::cin >> command;
			std::cout << std::endl;

			//Display help
			if (command.ToLowercase() == "help")
			{
				std::cout << "Commands:\n"
					<< " - pickup <item number>\n"
					<< " - list\n\n"

					<< " - inventory\n\n"

					<< " - leave\n";
			}
			else if (command.ToLowercase() == "pickup")
			{
				unsigned int itemNumber;

				//Get input number and subtract one (array starts at 0, not 1)
				std::cin >> itemNumber;
				itemNumber--;

				//Make sure the chosen enemy index is within bounds
				if (itemNumber >= m_items.size())
				{
					std::cout << "That item does not exist!" << std::endl;
				}
				else
				{
					//Add item to player inventory
					player->Pickup(m_items[itemNumber]);

					std::cout << "Picked up " << m_items[itemNumber]->GetName() << std::endl;

					//Remove item from room inventory
					m_items.erase(m_items.begin() + itemNumber);

					//If there are no more items left to pickup, leave room command
					if(m_items.empty())
						break;

					ListItems();
				}
			}
			else if (command.ToLowercase() == "list")
			{
				ListItems();
				continue;
			}
			else if (command.ToLowercase() == "inventory")
			{
				player->DisplayInventory();
			}
			else if (command.ToLowercase() == "leave")
			{
				std::cout << "You left the items in their place." << std::endl;
				break;
			}
			else
			{
				std::cout << "Invalid command." << std::endl;
			}

			std::cout << std::endl;
		}
	}
}
