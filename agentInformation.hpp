#ifndef _AGENTINFORMATION_H_
#define _AGENTINFORMATION_H_

#include <string>
#include "location.hpp"

namespace smartH
{

	class AgentInformation
	{
		std::string m_id;
		std::string m_configuration;
		Location m_location;
		std::string m_log;
	public:
		AgentInformation() = default;
		void setID(const std::string& _id);
		void setConfiguration(const std::string& _config);
		void setLocation(const Location& _location);
		void addLog(const std::string& _comment);
		void printLog(); //TODO - parameter file
		const std::string& getID() const;
		const std::string& getConfiguration() const;
		const Location& getLocation() const;
	};

}//smartH
#endif // !_AGENTINFORMATION_H_

