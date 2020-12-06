#ifndef _LOCATION_H_
#define _LOCATION_H_

#include <string>

using namespace std;

namespace smartH
{

	class Location
	{
		string m_building; 
		string m_floor;
		string m_room;
	public:
		const static string m_all; //means all buildings, all floors or all rooms
	public:
		Location() = default;
		Location(const string& _building, const string& _floor, const string& _room);
		void setBuilding(const string& _building);
		void setFloor(const string& _floor);
		void setRoom(const string& _room);
		const string& getBuilding() const;
		const string& getFloor() const;
		const string& getRoom() const;
		bool operator==(const Location& _location) const;
	};

} //smartH
#endif //_LOCATION_H_
