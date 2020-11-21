#ifndef _INTERFACE_RECEIVER_H
#define _INTERFACE_RECEIVER_H

#include <memory>
#include "event.hpp"

using namespace std;

namespace smartH
{
	class IReceiver
	{
	public:
		virtual void receiveEvent(const shared_ptr<const Event>& _event) = 0;
	};

} //smartH

#endif //_INTERFACE_RECEIVER_H
