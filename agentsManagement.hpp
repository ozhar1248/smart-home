#ifndef _AGENT_MANAGEMENT_H
#define _AGENT_MANAGEMENT_H

#include <vector>
#include "agentInerface.hpp"
#include "subscriptionInterface.hpp"

using namespace std;

namespace smartH
{
	
	class AgentManagement
	{
	public:
		AgentManagement(const vector<shared_ptr<IAgent>>& _agentVec, const shared_ptr<const ISubscription> _subscriptions);
	};
} //smartH
#endif // !_AGENT_MANAGEMENT_H

