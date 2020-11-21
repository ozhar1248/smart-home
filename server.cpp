#include "server.hpp"
#include "subscriptionInterface.hpp"
#include "subscriptions.hpp"
#include "agentsManagement.hpp"

using namespace std;
using namespace smartH;

Server::Server()
{
	vector<shared_ptr<IAgent>> vecAgents;
	shared_ptr<IAgent> agent(new Agent(IAgent::Sensor,"1","xxx",Location("a1", "2", "3")));
	vecAgents.push_back(agent);
	vecAgents.push_back(shared_ptr<IAgent>(new Agent(IAgent::Controller, "2", "xxx", Location("a2", "3", "4"))));
	shared_ptr<ISubscription> subs(new Subscriptions);
	subs->subscribe(vecAgents[1], shared_ptr<Location>(new Location(Location::m_all, "2", "3")));
	AgentManagement(vecAgents, subs);
	
}
