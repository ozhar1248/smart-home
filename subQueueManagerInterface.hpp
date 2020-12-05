#ifndef _SUBQUEUEMANAGERINTERFACE_H
#define _SUBQUEUEMANAGERINTERFACE_H

#include <memory>
#include "event.hpp"
#include "receiverInterface.hpp"

using namespace std;

namespace smartH
{

	class ISubQueueManager : public IReceiver
	{
	public:
		virtual void SendEvent(shared_ptr<Event> _event) = 0;
		virtual void stop() = 0;
	};//ISubQueueManager

} //smartH
#endif // !_SUBQUEUEMANAGERINTERFACE_H
