#include "location.hpp"

using namespace std;
using namespace smartH;

const string Location::m_all = "all";

Location::Location(const string& _building, const string& _floor, const string& _room)
	:m_building(_building)
	,m_floor(_floor)
	,m_room(_room)
{
}

void Location::setBuilding(const string& _building)
{
	m_building = m_building;
}

void Location::setFloor(const string& _floor)
{
	m_floor = _floor;
}

void Location::setRoom(const string& _room)
{
	m_room = _room;
}

const string& Location::getBuilding() const
{
	return m_building;
}

const string& Location::getFloor() const
{
	return m_floor;
}

const string& Location::getRoom() const
{
	return m_room;
}

bool Location::operator==(const Location& _location) const
{
	return m_building == _location.m_building && m_floor == _location.m_floor && m_room == _location.m_room;
}
