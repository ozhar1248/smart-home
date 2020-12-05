#include "agentsManagement.hpp"
#include "subQueueManager.hpp"
#include "queueManager.hpp"
#include <chrono>
#include <thread>

using namespace smartH;


const int NUM_OF_THREADS = 4;

AgentManagement::AgentManagement(const vector<shared_ptr<IAgent>>& _agentVec, const shared_ptr<const ISubscription> _subscriptions)
{
	shared_ptr<IReceiver> subQueues(new SubQueueManager(_agentVec, _subscriptions, NUM_OF_THREADS));
	shared_ptr<IReceiver> mainQueue(new QueueManager(subQueues));

	int sizeAgents = _agentVec.size();
	for (int i = 0; i < sizeAgents; ++i)
	{
		_agentVec[i]->start(mainQueue);
	}

	_agentVec[0]->sendEvent(shared_ptr<Event>(new Event("payload1", "type")));
	_agentVec[0]->sendEvent(shared_ptr<Event>(new Event("payload2", "type")));
	_agentVec[4]->sendEvent(shared_ptr<Event>(new Event("payload3", "type")));
	_agentVec[4]->sendEvent(shared_ptr<Event>(new Event("payload4", "type")));
	_agentVec[4]->sendEvent(shared_ptr<Event>(new Event("payload5", "type")));
	_agentVec[7]->sendEvent(shared_ptr<Event>(new Event("payload6", "type")));

	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	subQueues->stop();
	mainQueue->stop();

	for (int i = 0; i < sizeAgents; ++i)
	{
		_agentVec[i]->printLog();
	}
}
