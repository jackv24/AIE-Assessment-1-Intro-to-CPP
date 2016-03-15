#include "Player.h"
#include "Helper.h"

Player::Player()
{
	m_name = "You";
	m_health = 100;
}

Player::~Player()
{

}

void Player::Action()
{
	bool running = true;

	String command;

	while (running)
	{
		ClearInput();

		std::cout << "\nEnter a command: ";
		std::cin >> command;
		std::cout << std::endl;

		if (command.ToLowercase() == "attack")
		{
			//TODO: Implement attacks
			std::cout << "\nYou don't have any attacks, you must run!" << std::endl;

			running = false;
		}
		else if (command.ToLowercase() == "inventory")
		{
			DisplayInventory();
		}
		else if (command.ToLowercase() == "help")
		{
			std::cout << "Commands:\n"
				<< " - attack\n"
				<< " - inventory\n";
		}
		else
		{
			std::cout << "\nInvalid command." << std::endl;
		}
	}
}
