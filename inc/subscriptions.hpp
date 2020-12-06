#ifndef _SUBSCRIPTIONS_H_
#define _SUBSCRIPTIONS_H_

#include "location.hpp"
#include "subscriptionInterface.hpp"
#include <map>
#include <memory>
#include <vector>

using namespace std;

namespace smartH
{

	class Subscriptions : public ISubscription
	{
		map<shared_ptr<IAgent>, vector<shared_ptr<Location>>> m_subMap;
	public:
		typedef map<shared_ptr<IAgent>, vector<shared_ptr<Location>>>::const_iterator itrMap;
		typedef vector<shared_ptr<Location>> vecLocations;
		typedef vector<shared_ptr<Location>>::iterator vecLocationsItr;
	public:
		Subscriptions() = default;
		void subscribe(const shared_ptr<IAgent>& _agent, const shared_ptr<Location>& _location);
		void getAgentsRegistered(const shared_ptr<const Event>& event, vector<shared_ptr<IAgent>>& _vector) const;
	}; //Subscriptions

} //smartH

#endif //_SUBSCRIPTIONS_H_
