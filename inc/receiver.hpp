#ifndef _RECEIVER_H_
#define _RECEIVER_H_

#include <memory>
#include "subscriptionInterface.hpp"
#include "receiverInterface.hpp"

namespace smartH
{
	class Receiver : public IReceiver
	{
		shared_ptr<const ISubscription> m_subscriptions;
	public:
		Receiver(shared_ptr<const ISubscription> _subscriptions)
			:m_subscriptions(_subscriptions) {}
		void receiveEvent(const shared_ptr<const Event>& _event)
		{
			vector<shared_ptr<IAgent>> comAgents;
			m_subscriptions->getAgentsRegistered(_event, comAgents);
			for (auto itr = comAgents.begin(); itr != comAgents.end(); ++itr)
			{
				(*itr)->publish(_event);
			}
		}
	};

}
#endif // !_RECEIVER_H_

