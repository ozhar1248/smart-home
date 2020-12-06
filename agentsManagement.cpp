#include "agentsManagement.hpp"
#include "subQueueManager.hpp"
#include "queueManager.hpp"

using namespace smartH;


const int NUM_OF_THREADS = 4;

AgentManagement::AgentManagement(const vector<shared_ptr<IAgent>>& _agentVec, const shared_ptr<const ISubscription> _subscriptions)
	:m_agentVec(_agentVec)
	,m_secondRec(new SubQueueManager(_agentVec, _subscriptions, NUM_OF_THREADS))
	,m_firstRec(new QueueManager(m_secondRec))
{
	int sizeAgents = _agentVec.size();
	for (int i = 0; i < sizeAgents; ++i)
	{
		_agentVec[i]->start(m_firstRec);
	}

	_agentVec[0]->sendEvent(shared_ptr<Event>(new Event("payload1", "type")));
	_agentVec[0]->sendEvent(shared_ptr<Event>(new Event("payload2", "type")));
	_agentVec[4]->sendEvent(shared_ptr<Event>(new Event("payload3", "type")));
	_agentVec[4]->sendEvent(shared_ptr<Event>(new Event("payload4", "type")));
	_agentVec[4]->sendEvent(shared_ptr<Event>(new Event("payload5", "type")));
	_agentVec[7]->sendEvent(shared_ptr<Event>(new Event("payload6", "type")));

}

smartH::AgentManagement::~AgentManagement()
{
	m_secondRec->stop();
	m_firstRec->stop();

	int sizeAgents = m_agentVec.size();
	for (int i = 0; i < sizeAgents; ++i)
	{
		m_agentVec[i]->printLog();
	}
}
