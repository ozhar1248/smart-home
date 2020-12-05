#include "event.hpp"

using namespace std;
using namespace smartH;

namespace smartH
{
	Event::Event(const string& _payload, const string& _type, const Location& _location)
		:m_payload(_payload)
		, m_type(_type)
		, m_location(_location)
	{
	}

	Event::Event(const string& _payload, const string& _type)
		:m_payload(_payload)
		, m_type(_type)
		, m_location()
	{
	}

	const Location& Event::getLocation() const
	{
		return m_location;
	}

	const string& Event::getPayload() const
	{
		return m_payload;
	}

	const string& Event::getType() const
	{
		return m_type;
	}

	void Event::setLocation(const Location& _location)
	{
		m_location = _location;
	}

	Event::operator string() const
	{
		return "Event type:" + m_type + " Location: " + m_location.getBuilding() + "::" + m_location.getFloor() + "::" + m_location.getRoom() + "\n";
	}

	void operator<<(ostream& out, const Event event)
	{
		out << "Event type:" + event.getType() + " Location: " + event.getLocation().getBuilding() + "::" + event.getLocation().getFloor() + "::" + event.getLocation().getRoom() + "\n";
	}
} //smartH

