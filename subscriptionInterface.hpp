#ifndef _INTERFACE_SUBSCRIPTIONS_H
#define _INTERFACE_SUBSCRIPTIONS_H

#include "location.hpp"
#include "agentInerface.hpp"
#include <memory>
#include <vector>

using namespace std;

namespace smartH
{
	class ISubscription
	{
	public:
		virtual void subscribe(const shared_ptr<IAgent>& _agent, const shared_ptr<Location>& _location) = 0;
		virtual void getAgentsRegistered(const shared_ptr<const Event>& event, vector<shared_ptr<IAgent>>& _vector) const = 0;
	};

} //smartH

#endif //_INTERFACE_SUBSCRIPTIONS_H
