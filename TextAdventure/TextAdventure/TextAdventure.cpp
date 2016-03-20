/*
	Author:			Jack Vine
	Date Created:	6/3/2016
	Brief:			The main class. Accepts general input, and acts accordingly.
					(Room-related input is handled by the room, not here)
*/

#include <iostream>
#include <time.h>
#include "Helper.h"
#include "Windows.h"
#include "Map.h"
#include "Room.h"
#include "Player.h"

using namespace std;

HANDLE hConsole;

void PrintHelp()
{
	//Make text white
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	cout << "Commands:\n"
		<< " - move <direction>\n"
		<< " - go <direction>\n"
		<< " - walk <direction>\n"
		<< " - run <direction>\n\n"

		<< " - inventory\n\n"

		<< " - quit\n"
		<< " - exit\n";
}

int main()
{
	//Setup seed for random elements
	srand((unsigned int)time(NULL));

	// Console handle to change colour
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	Player* player = new Player();

	//Create the map
	Map map;

	//Set console text colour to white
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	//Print out the description of the current room
	cout << map.GetCurrentRoom().GetDescription() << endl;

	bool running = true;
	while (running)
	{
		if (!player->IsAlive())
			break;

		//Set input to be grey text
		SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);

		//Get and store the first command
		String command;
		cout << "\nEnter a command: ";
		cin >> command;
		cout << endl << endl;

		if (command.ToLowercase() == "move" ||
			command.ToLowercase() == "go" ||
			command.ToLowercase() == "walk" ||
			command.ToLowercase() == "run")
		{
			//Get and store the second part of the command, the direction
			String direction;
			cin >> direction;

			//Set console text colour to white
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

			if (map.Move(direction.ToLowercase()))
			{
				//Change the text colour based on what room it is
				if (map.GetCurrentRoom().GetType() == Room::Type::MONSTER)
					//Bright red for monster
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				else if (map.GetCurrentRoom().GetType() == Room::Type::TREASURE)
					//Bright green for treasure
					SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

				cout << map.GetCurrentRoom().GetDescription() << endl;
				map.GetCurrentRoom().Update(player);
			}
		}
		else if (command.ToLowercase() == "inventory")
		{
			//Make text white
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

			player->DisplayInventory();
		}
		else if (command.ToLowercase() == "help")
			PrintHelp();
		else if (command.ToLowercase() == "quit" || command.ToLowercase() == "exit")
		{
			//Make text white
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

			cout << "...quitter.\n\n";
			running = false;
		}
		else
		{
			//Make text white
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

			cout << "That is not a valid command!\n";
		}

		//Clear the input stream (ensures a chain of invalid commands does not continue)
		ClearInput();
	}

	//Make text white
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	cout << "\nThanks for playing!\n" << endl;

	delete player;

	system("PAUSE");

    return 0;
}

