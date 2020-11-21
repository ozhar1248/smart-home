#ifndef _AGENTINFORMATION_H_
#define _AGENTINFORMATION_H_

#include <string>
#include "location.hpp"

using namespace std;

namespace smartH
{

	class AgentInformation
	{
		string m_id;
		string m_configuration;
		Location m_location;
		string m_log;
	public:
		AgentInformation() = default;
		AgentInformation(const string& _id, const string& _config, const Location& _location);
		void setID(const string& _id);
		void setConfiguration(const string& _config);
		void setLocation(const Location& _location);
		void addLog(const string& _comment);
		//void printLog(); TODO - parameter file
		const string& getID() const;
		const string& getConfiguration() const;
		const Location& getLocation() const;
	};

}//smartH
#endif // !_AGENTINFORMATION_H_

