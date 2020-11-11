#ifndef _IAGENT_H
#define _IAGENT_H

#include <memory>
#include <string>
#include "event.hpp"
#include "agentInformation.hpp"

namespace smartH
{

	class IAgent
	{
	public:
		enum Type { Controller = 0, Sensor = 1};
		virtual int getType() const = 0;
		virtual void receiveEvent(const std::shared_ptr<const Event>& _event) = 0;
		virtual const AgentInformation& getInfo() const =0;
		virtual void setInfo(const AgentInformation& _info) =0;
	}; //IAgent

} //smartH

#endif //_IAGENT_H
