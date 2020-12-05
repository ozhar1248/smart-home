#include "server.hpp"
#include "subscriptionInterface.hpp"
#include "subscriptions.hpp"
#include "agentsManagement.hpp"

using namespace std;
using namespace smartH;

Server::Server()
{
	vector<shared_ptr<IAgent>> vecAgents;
	vecAgents.push_back(shared_ptr<IAgent>(new Agent(IAgent::Sensor, "0", "xxx", Location("b", "2", "2"))));
	vecAgents.push_back(shared_ptr<IAgent>(new Agent(IAgent::Controller, "1", "xxx", Location("b", "3", "4"))));
	vecAgents.push_back(shared_ptr<IAgent>(new Agent(IAgent::Controller, "2", "xxx", Location("b", "3", "4"))));
	vecAgents.push_back(shared_ptr<IAgent>(new Agent(IAgent::Controller, "3", "xxx", Location("b", "3", "4"))));
	vecAgents.push_back(shared_ptr<IAgent>(new Agent(IAgent::Sensor, "4", "xxx", Location("b", "1", "1"))));
	vecAgents.push_back(shared_ptr<IAgent>(new Agent(IAgent::Controller, "5", "xxx", Location("b", "3", "4"))));
	vecAgents.push_back(shared_ptr<IAgent>(new Agent(IAgent::Controller, "6", "xxx", Location("b", "3", "4"))));
	vecAgents.push_back(shared_ptr<IAgent>(new Agent(IAgent::Sensor, "7", "xxx", Location("b", "1", "3"))));
	
	shared_ptr<ISubscription> subs(new Subscriptions);
	subs->subscribe(vecAgents[1], shared_ptr<Location>(new Location(Location::m_all, Location::m_all, "1")));
	subs->subscribe(vecAgents[1], shared_ptr<Location>(new Location(Location::m_all, Location::m_all, "3")));
	subs->subscribe(vecAgents[2], shared_ptr<Location>(new Location(Location::m_all, Location::m_all, "1")));
	subs->subscribe(vecAgents[3], shared_ptr<Location>(new Location(Location::m_all, Location::m_all, "2")));
	subs->subscribe(vecAgents[5], shared_ptr<Location>(new Location(Location::m_all, Location::m_all, "3")));
	subs->subscribe(vecAgents[6], shared_ptr<Location>(new Location(Location::m_all, Location::m_all, "1")));
	subs->subscribe(vecAgents[6], shared_ptr<Location>(new Location(Location::m_all, Location::m_all, "2")));
	AgentManagement(vecAgents, subs);
	
}
