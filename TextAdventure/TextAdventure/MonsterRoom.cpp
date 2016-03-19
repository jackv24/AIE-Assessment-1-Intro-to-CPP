#include "MonsterRoom.h"
#include "Demon.h"
#include <time.h>

MonsterRoom::MonsterRoom()
{
	SetType(Type::MONSTER);
	SetDescription("You encounter a monster room!");
}

MonsterRoom::~MonsterRoom()
{
	if (!m_characters.empty())
	{
		//Delete character pointers (that aren't the player - that is handled elsewhere)
		for (int i = 1; i < m_characters.size(); i++)
		{
			delete m_characters[i];
		}
		//Then clear vector
		m_characters.clear();
	}
}

void MonsterRoom::Update(Character* player)
{
	//If the character vector hasn't been populated
	if (m_characters.empty())
	{
		m_characters.push_back(player);

		srand(time(NULL));

		int numEnemies = rand() % 3;

		for (int i = 0; i <= numEnemies; i++)
		{
			m_characters.push_back(new Demon());
		}
	}

	if (IsClear())
		std::cout << "\nThere are no enemies here.\n";
	else
	{
		//While the room still has enemies
		while (!IsClear())
		{
			//If the player is dead, don't let any character perform an action
			if (!m_characters[0]->IsAlive())
				break;

			DisplayInfo();

			//Let each character take a turn
			for (Character* character : m_characters)
			{
				//If the character is alive, it can perform actions
				if(character->IsAlive() && m_characters[0]->IsAlive())
					character->Action(m_characters);
			}
		}

		DisplayInfo();
	}
}

bool MonsterRoom::IsClear()
{
	//Iterate through the monsters only (skip player at index 0)
	for (int i = 1; i < m_characters.size(); i++)
	{
		//If there is still a monster alive, the room is not clear
		if (m_characters[i]->IsAlive())
			return false;
	}

	//If the room is clear, return true
	return true;
}

void MonsterRoom::DisplayInfo()
{
	std::cout << "\nEnemies:\n";
	for (int i = 1; i < m_characters.size(); i++)
	{
		std::cout << i << ". " << m_characters[i]->GetName() << " (" << m_characters[i]->GetHealth() << "HP)" << "\n";
	}

	//Print out the HP of the player
	std::cout << "\nYour HP: " << m_characters[0]->GetHealth() << std::endl;
}