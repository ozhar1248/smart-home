#ifndef _IAGENT_H
#define _IAGENT_H

#include <memory>
#include <string>
#include "event.hpp"
#include "agentInformation.hpp"
#include "receiverInterface.hpp"

using namespace std;

namespace smartH
{
	class IAgent
	{
	public:
		enum Type { Controller = 0, Sensor = 1};
	public:
		virtual int getType() const = 0;
		virtual const AgentInformation& getInfo() const =0;
		virtual void publish(const shared_ptr<const Event>& _event) = 0;
		virtual void start(shared_ptr<IReceiver> _receiver) = 0;
		virtual void sendEvent(shared_ptr<Event> _event) = 0;
		virtual void printLog() const = 0;
	}; //IAgent
} //smartH
#endif //_IAGENT_H
