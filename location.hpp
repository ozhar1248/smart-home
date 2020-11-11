#ifndef _LOCATION_H_
#define _LOCATION_H_

#include <string>

namespace smartH
{

	class Location
	{
		std::string m_building; 
		std::string m_floor;
		std::string m_room;
	public:
		const static std::string m_all; //means all buildings, all floors or all rooms
	public:
		Location() = default;
		void setBuilding(const std::string& _building);
		void setFloor(const std::string& _floor);
		void setRoom(const std::string& _room);
		const std::string& getBuilding() const;
		const std::string& getFloor() const;
		const std::string& getRoom() const;
	};

} //smart
#endif //_LOCATION_H_
