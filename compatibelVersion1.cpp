#include "compatibelVersion1.hpp"

using namespace std;
using namespace smartH;

bool CompatibleVer1::isCompatible(const shared_ptr<const Event>& _event, const shared_ptr<const Location>& _location) const
{
    if (_location->getBuilding() != Location::m_all)
    {
        if (_event->getLocation().getBuilding() != _location->getBuilding())
        {
            return false;
        }
    }
    if (_location->getFloor() != Location::m_all)
    {
        if (_event->getLocation().getFloor() != _location->getFloor())
        {
            return false;
        }
    }
    if (_location->getRoom() != Location::m_all)
    {
        if (_event->getLocation().getRoom() != _location->getRoom())
        {
            return false;
        }
    }
    return true;
}
