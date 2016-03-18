#include "Sword.h"
#include <time.h>

Sword::Sword()
{
	m_name = "Sword";
	m_type = Type::WEAPON;

	srand(time(NULL));
}

Sword::~Sword()
{

}

void Sword::Use(Character* target)
{
	//Damage between 20 and 50
	target->RemoveHealth(rand() % 30 + 20);
}
