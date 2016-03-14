#include "Room.h"

Room::Room()
{
	//Set default values - will be empty room by default when map loading is implemented
	SetDescription("You are in an empty room");
	m_type = Type::EMPTY;
}

Room::~Room()
{

}


void Room::SetDescription(String description)
{
	m_description = description;
}

void Room::SetDescription(const char* description)
{
	m_description = description;
}

String Room::GetDescription()
{
	return m_description;
}


Room::Type Room::GetType()
{
	return m_type;
}

void Room::SetType(Type type)
{
	m_type = type;
}

void Room::Update(Character* player)
{
	//Nothing to do in an empty room
}