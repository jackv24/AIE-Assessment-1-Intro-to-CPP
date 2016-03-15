#include "Player.h"
#include "Helper.h"
#include "Windows.h"

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
		std::cout << std::endl;

		//Light red for descriptions
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);

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
