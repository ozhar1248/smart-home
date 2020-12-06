#include "uncopyable.hpp"

ds::Uncopyable::Uncopyable()
{
}

ds::Uncopyable::Uncopyable(const Uncopyable& _obj)
{

}

ds::Uncopyable& ds::Uncopyable::operator=(const Uncopyable&)
{
	return *this;
}
