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
	public:
		Agent(enum Type _type, const string& _id, const string& _config, const Location& _location);
		int getType() const;
		const AgentInformation& getInfo() const;
		void publish(const shared_ptr<const Event>& _event);
		void startReceivingEvents(shared_ptr<IReceiver> _receiver);
	};

} //smartH
#endif // !_AGENT_H_

