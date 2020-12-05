#include "subQueueManager.hpp"

using namespace smartH;
using namespace std;
using namespace ds;



void dequeue(QueueTS<PackagedEvent>* qu, const vector<shared_ptr<IAgent>>& _agents)
{
	PackagedEvent eventPtr;

	while (true)
	{
		if (qu->dequeue(eventPtr) == 1)
		{
			break;
		}
		_agents[eventPtr.getDestination()]->publish(eventPtr.getEventPtr());
	}
}

SubQueueManager::SubQueueManager(const vector<shared_ptr<IAgent>>& _agents, const shared_ptr<const ISubscription>& _subscriptions, size_t numOfThreads)
	:m_agents(_agents)
	,m_subscriptions(_subscriptions)
	,m_numOfThreads(numOfThreads)
	, m_arrQueues(new QueueTS<PackagedEvent>[m_numOfThreads])
{
	for (size_t i = 0; i < numOfThreads; ++i)
	{
		m_vecThreads.push_back(thread(dequeue, &m_arrQueues[i], m_agents));
	}
}

smartH::SubQueueManager::~SubQueueManager()
{
	delete[] m_arrQueues;
}

void SubQueueManager::SendEvent(shared_ptr<Event> _event)
{
	vector<shared_ptr<IAgent>> agentsCompatible;
	m_subscriptions->getAgentsRegistered(_event, agentsCompatible);
	int size = m_agents.size();
	for (int i = 0; i < size; ++i)
	{
		int sizeAgents = agentsCompatible.size();
		for (int j = 0; j < sizeAgents; ++j)
		{
			if (m_agents[i] == agentsCompatible[j])
			{
				PackagedEvent newEvent;
				newEvent.setDestination(i);
				newEvent.setEventPtr(_event);
				m_arrQueues[i % m_numOfThreads].enqueue(newEvent);
				break;
			}
		}
	}
}

void SubQueueManager::stop()
{
	for (size_t i = 0; i < m_numOfThreads; ++i)
	{
		m_arrQueues[i].stop();
		m_vecThreads[i].join();
	}
}

smartH::PackagedEvent::PackagedEvent()
	:m_eventPtr(nullptr)
	, m_destination(0)
{
}

smartH::PackagedEvent::PackagedEvent(const shared_ptr<Event>& _event, const size_t& _destination)
	:m_eventPtr(_event)
	,m_destination(_destination)
{
}

shared_ptr<Event> smartH::PackagedEvent::getEventPtr() const
{
	return m_eventPtr;
}

size_t smartH::PackagedEvent::getDestination() const
{
	return m_destination;
}

void smartH::PackagedEvent::setEventPtr(const shared_ptr<Event>& _event)
{
	m_eventPtr = _event;
}

void smartH::PackagedEvent::setDestination(const size_t& _destination)
{
	m_destination = _destination;
}
