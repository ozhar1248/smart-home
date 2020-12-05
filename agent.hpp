#ifndef _AGENT_H_
#define _AGENT_H_

#include <string>
#include <memory>
#include <iostream>
#include "agentInerface.hpp"
#include "location.hpp"
#include "receiverInterface.hpp"

using namespace std;

namespace smartH
{

	class Agent : public IAgent
	{
		AgentInformation m_info;
		enum Type m_type;
		shared_ptr<IReceiver> m_receiver;
	public:
		Agent(enum Type _type, const string& _id, const string& _config, const Location& _location);
		int getType() const;
		const AgentInformation& getInfo() const;
		void publish(const shared_ptr<const Event>& _event);
		void start(shared_ptr<IReceiver> _receiver);
		void sendEvent(shared_ptr<Event> _event);
		void printLog() const;
	};

} //smartH
#endif // !_AGENT_H_

