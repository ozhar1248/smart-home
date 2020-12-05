#ifndef _EVENT_H_
#define _EVENT_H_

#include "location.hpp"
#include <string>
#include <iostream>

using namespace std;

namespace smartH
{

	class Event
	{
		string m_payload;
		Location m_location;
		string m_type;
		//Timestamp m_time;
	public:
		//TODO default constructors, getters setters
		Event(const string& _payload, const string& _type, const Location& _location);
		Event(const string& _payload, const string& _type);
		const Location& getLocation() const;
		const string& getPayload() const;
		const string& getType() const;
		void setLocation(const Location& _location);
		operator string() const;
	}; //Event

	void operator<<(ostream& out, const Event event);

} //smartH

#endif // !_EVENT_H_

