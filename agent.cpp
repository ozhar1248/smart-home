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
	m_info.addLog("Event received at agent id " + m_info.getID() + " ->> ");
	m_info.addLog(*_event);
}

void smartH::Agent::start(shared_ptr<IReceiver> _receiver)
{
	m_receiver = _receiver;
}

void smartH::Agent::sendEvent(shared_ptr<Event> _event)
{
	// check if its not null
	_event->setLocation(m_info.getLocation());
	m_receiver->SendEvent(_event);
}

void smartH::Agent::printLog() const
{
	cout << m_info.getLog() << endl;
}


