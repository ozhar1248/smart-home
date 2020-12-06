#ifndef _UNCOPYABLE_H_
#define _UNCOPYABLE_H_

#include <iostream>

namespace ds
{

	class Uncopyable 
	{
	public:
		Uncopyable();
	private:
		Uncopyable(const Uncopyable&);
		Uncopyable& operator=(const Uncopyable&);
	};

} //ds
#endif // !_UNCOPYABLE_H_
