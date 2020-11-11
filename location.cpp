#include "location.hpp"

void smartH::Location::setBuilding(const std::string& _building)
{
	m_building = m_building;
}

void smartH::Location::setFloor(const std::string& _floor)
{
	m_floor = _floor;
}

void smartH::Location::setRoom(const std::string& _room)
{
	m_room = _room;
}

const std::string& smartH::Location::getBuilding() const
{
	return m_building;
}

const std::string& smartH::Location::getFloor() const
{
	return m_floor;
}

const std::string& smartH::Location::getRoom() const
{
	return m_room;
}
