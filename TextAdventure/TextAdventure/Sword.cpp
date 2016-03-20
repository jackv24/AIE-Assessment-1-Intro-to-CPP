#include "Sword.h"

Sword::Sword()
{
	m_name = "Sword";
	m_type = Type::WEAPON;
}

Sword::~Sword()
{

}

void Sword::Use(Character* target)
{
	//Damage between 20 and 50
	target->RemoveHealth(rand() % 30 + 20);
}
