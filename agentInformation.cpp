#include "agentInformation.hpp"

using namespace std;
using namespace smartH;

AgentInformation::AgentInformation(const string& _id, const string& _config, const Location& _location)
	:m_id(_id)
	,m_configuration(_config)
	,m_location(_location)
{
}

void AgentInformation::setID(const string& _id)
{
	m_id = _id;
}

void AgentInformation::setConfiguration(const string& _config)
{
	m_configuration = _config;
}

void AgentInformation::setLocation(const Location& _location)
{
	m_location = _location;
}

void AgentInformation::addLog(const string& _comment)
{
	m_log += _comment;
}

const string& AgentInformation::getID() const
{
	return m_id;
}

const string& AgentInformation::getConfiguration() const
{
	return m_configuration;
}

const Location& AgentInformation::getLocation() const
{
	return m_location;
}
