#ifndef _SUBSCRIPTIONS_H_
#define _SUBSCRIPTIONS_H_

#include "location.hpp"
#include "agentInerface.hpp"
#include <map>
#include <memory>
#include <vector>

namespace smartH
{

	class Subscriptions
	{
		std::map<std::shared_ptr<const IAgent>, std::vector<std::shared_ptr<const Location>>> m_subMap;
	public:
		Subscriptions() = default;
		void subscribe(const std::shared_ptr<const IAgent>& _agent, const std::shared_ptr<const Location>& _location);
	}; //Subscriptions

} //smartH

#endif //_SUBSCRIPTIONS_H_
