#include "Demon.h"
#include <time.h>

Demon::Demon()
{
	m_name = "Demon";
	m_health = 50;
}

Demon::~Demon()
{
}

void Demon::Action(std::vector<Character*> characters)
{
	srand(time(NULL));

	//The enemy to attack
	Character* target;
	do
	{
		//Select a random enemy
		target = characters[rand() % characters.size()];
	} //Make sure the selected target is not itself
	while (target == this);

	//Attack target
	std::cout << "\n" << m_name << " attacked " << target->GetName() << "\n\n";

	int damage = rand() % 30 + 10;

	target->RemoveHealth(damage);
}