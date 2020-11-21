#include "agentsManagement.hpp"
#include "receiver.hpp"

using namespace smartH;

AgentManagement::AgentManagement(const vector<shared_ptr<IAgent>>& _agentVec, const shared_ptr<const ISubscription> _subscriptions)
{
	shared_ptr<IReceiver> rec(new Receiver(_subscriptions));
	_agentVec[0]->startReceivingEvents(rec);

}
