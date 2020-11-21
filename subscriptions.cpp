#include "subscriptions.hpp"
#include "compatibelVersion1.hpp"

using namespace std;
using namespace smartH;

void Subscriptions::subscribe(const shared_ptr<IAgent>& _agent, const shared_ptr<Location>& _location)
{
	itrMap itr = m_subMap.find(_agent);
	if (itr == m_subMap.end())
	{
		m_subMap[_agent].push_back(_location);
		return;
	}
	vecLocations& vec = m_subMap[_agent];
	vecLocationsItr itrV = vec.begin();
	while (itrV != vec.end())
	{
		const Location& loc = *(*itrV);
		if (loc == *_location)
		{
			return; // error. location already exists
		}
		++itrV;
	}
	vec.push_back(_location);
}

void Subscriptions::getAgentsRegistered(const shared_ptr<const Event>& _event, vector<shared_ptr<IAgent>>& _vector) const
{
	const shared_ptr<const ICompatibility> comp(new CompatibleVer1);
	itrMap itr = m_subMap.begin();
	while (itr != m_subMap.end())
	{
		vecLocations vec = itr->second;
		int sizeVec = vec.size();
		for (int i = 0; i < sizeVec; ++i)
		{
			if (comp->isCompatible(_event, vec[i]))
			{
				_vector.push_back(itr->first);
				break;
			}
		}
		++itr;
	}
}
