#ifndef _INTERFACE_SUBSCRIPTIONS_H
#define _INTERFACE_SUBSCRIPTIONS_H

#include "location.hpp"
#include "agentInerface.hpp"
#include <memory>

namespace smartH
{
	class ISubscription
	{
	public:
		virtual void subscribe(const std::shared_ptr<const IAgent>& _agent, const std::shared_ptr<const Location>& _location) = 0;
	};
} //smartH

#endif //_INTERFACE_SUBSCRIPTIONS_H
