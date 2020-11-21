#ifndef _COMPATIBLE_INTERFACE_H_
#define _COMPATIBLE_INTERFACE_H_

#include <memory>
#include "event.hpp"

using namespace std;

namespace smartH
{
	class ICompatibility
	{
	public:
		virtual bool isCompatible(const shared_ptr<const Event>& _event, const shared_ptr<const Location>& _location) const = 0;
	}; //ICompatibility

} //smartH
#endif // !_COMPATIBLE_INTERFACE_H_

