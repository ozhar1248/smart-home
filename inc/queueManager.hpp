#ifndef _QUEUE_MANAGER_H
#define _QUEUE_MANAGER_H

#include <memory>
#include <thread>
#include "queueTS.hpp"
#include "event.hpp"
#include "receiverInterface.hpp"

using namespace ds;
using namespace std;

namespace smartH
{
	class QueueManager : public IReceiver
	{
		QueueTS<shared_ptr<Event>> m_eventsQueue;
		shared_ptr<IReceiver> m_receiver;
		thread m_deqThread;
	public:
		QueueManager(const shared_ptr<IReceiver>& _receiver);
		void SendEvent(shared_ptr<Event> _event);
		void stop();
	};
} //smartH
#endif //_QUEUE_MANAGER_H
