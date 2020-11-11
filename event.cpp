#include "event.hpp"

smartH::Event::Event(const std::string& _payload, const std::string& _type, const Location& _location)
	:m_payload(_payload)
	,m_type(_type)
	,m_location(_location)
{
}
