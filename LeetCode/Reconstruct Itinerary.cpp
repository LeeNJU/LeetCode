#include<vector>
#include<unordered_map>
#include<string>
#include<list>
#include<stack>

std::vector<std::string> findItinerary(std::vector<std::pair<std::string, std::string>> tickets) 
{
	std::unordered_map<std::string, std::list<std::string>> graph;
	for (int i = 0; i < tickets.size(); i++)
		graph[tickets[i].first].push_back(tickets[i].second);

	std::vector<std::string> itinerary;
	std::stack<std::string> s;
	s.push("JFK");
	while (!s.empty())
	{

	}
	return std::vector<std::string>();
}