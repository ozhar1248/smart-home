#include <iostream>
#include "agent.hpp"


using namespace smartH;
using namespace std;

Agent::Agent(enum Type _type, const string& _id, const string& _config, const Location& _location)
	:m_info(_id, _config, _location),
	m_type(_type)
{
}

int Agent::getType() const
{
	return m_type;
}

const AgentInformation& Agent::getInfo() const
{
	return m_info;
}

void Agent::publish(const shared_ptr<const Event>& _event)
{
	cout << *_event;
}

void Agent::startReceivingEvents(shared_ptr<IReceiver> _receiver)
{
	_receiver->receiveEvent(shared_ptr<Event>(new Event("payload", "type", Location(m_info.getLocation().getBuilding(), m_info.getLocation().getFloor(), m_info.getLocation().getRoom()))));
}
