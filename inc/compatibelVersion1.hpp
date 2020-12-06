#ifndef _COMPATIBLE_VERSION1_H_
#define _COMPATIBLE_VERSION1_H_

#include "compatibleInterface.hpp"

using namespace std;

namespace smartH
{
	class CompatibleVer1 : public ICompatibility
	{
	public:
		bool isCompatible(const shared_ptr<const Event>& _event, const shared_ptr<const Location>& _location) const;
	}; //CompatibleVer1

} //smartH
#endif // !_COMPATIBLE_VERSION1_H_
