#include "Weapon.h"

Weapon::Weapon()
{
	m_name = "a weapon";
}

Weapon::~Weapon()
{

}

void Weapon::Use()
{
	std::cout << "The weaopn is useless. It did nothing." << std::endl;
}