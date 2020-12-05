#include <thread>
#include <iostream>
#include "queueManager.hpp"

using namespace std;
using namespace smartH;

void dequeue(QueueTS<shared_ptr<Event>>& qu, shared_ptr<IReceiver>& _receiver)
{
	shared_ptr<Event> ptrEvent;

	while (qu.dequeue(ptrEvent) != 1)
	{
		_receiver->SendEvent(ptrEvent);
	}
}

smartH::QueueManager::QueueManager(const shared_ptr<IReceiver>& _receiver)
	:m_receiver(_receiver)
	, m_deqThread(dequeue, ref(m_eventsQueue), ref(m_receiver))
{
}

void smartH::QueueManager::SendEvent(shared_ptr<Event> _event)
{
	m_eventsQueue.enqueue(_event);
}

void smartH::QueueManager::stop()
{
	m_eventsQueue.stop();
	m_deqThread.join();
}
