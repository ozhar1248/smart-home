#ifndef _SUBQUEUEMANAGER_H
#define _SUBQUEUEMANAGER_H

#include <memory>
#include "subscriptionInterface.hpp"
#include "queueTS.hpp"
#include "receiverInterface.hpp"

using namespace std;

namespace smartH
{
	class PackagedEvent
	{
	private:
		shared_ptr<Event> m_eventPtr;
		size_t m_destination;
	public:
		PackagedEvent();
		PackagedEvent(const shared_ptr<Event>& _event, const size_t& _destination);
		shared_ptr<Event> getEventPtr() const;
		size_t getDestination() const;
		void setEventPtr(const shared_ptr<Event>& _event);
		void setDestination(const size_t& _destination);
	};

	class SubQueueManager : public IReceiver
	{
		const vector<shared_ptr<IAgent>>& m_agents;
		shared_ptr<const ISubscription> m_subscriptions;
		size_t m_numOfThreads;
		vector<thread> m_vecThreads;
		ds::QueueTS<PackagedEvent>* m_arrQueues;
	public:
		SubQueueManager(const vector<shared_ptr<IAgent>>& _agents, const shared_ptr<const ISubscription>& _subscriptions, size_t numOfThreads);
		~SubQueueManager();
		void SendEvent(shared_ptr<Event> _event);
		void stop();
	};//SubQueueManager

} //smartH
#endif // !_SUBQUEUEMANAGER_H