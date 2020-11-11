#ifndef _EVENT_H_
#define _EVENT_H_

#include "location.hpp"
#include <string>

namespace smartH
{

	class Event
	{
		std::string m_payload;
		Location m_location;
		std::string m_type;
		//Timestamp m_time;
	public:
		//TODO default constructors, getters setters
		Event(const std::string& _payload, const std::string& _type, const Location& _location);
	}; //Event
} //smartH

#endif // !_EVENT_H_

