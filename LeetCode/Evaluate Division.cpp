#include<unordered_map>
#include<string>
#include<vector>
//题目描述:给定一组A / B = k的表达式，表示A和B之间的倍数关系，然后给定一组C / D形式的query，求出C和D之间的
//        倍数关系。例如给定a / b = 2.0, b / c = 3.0，求出这些query的值
//        a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
//解法描述:用图来表示倍数关系，然后从query的起始字符串开始深搜

bool dfs(std::unordered_map<std::string, std::vector<std::pair<std::string, double>>>& graph, std::unordered_map<std::string, bool> visited, std::string start, std::string& end, double& result)
{
	if (visited[start])
		return false;

	if (start == end)
	{
		result = 1.0;
		return true;
	}

	visited[start] = true;
	double val = 1.0;
	for (std::pair<std::string, double> p : graph[start])
	{
		if (dfs(graph, visited, p.first, end, val))
		{
			result = p.second * val;
			return true;
		}
	}

	return false;
}

std::vector<double> calcEquation(std::vector<std::pair<std::string, std::string>> equations, std::vector<double>& values, std::vector<std::pair<std::string, std::string>> queries) 
{
	std::unordered_map<std::string, std::vector<std::pair<std::string, double>>> graph;
	for (int i = 0; i < equations.size(); ++i)
	{
		graph[equations[i].first].push_back(std::pair<std::string, double>(equations[i].second, values[i]));
		graph[equations[i].second].push_back(std::pair<std::string, double>(equations[i].first, 1.0 / values[i]));
	}

	std::vector<double> result;
	for (int i = 0; i < queries.size(); ++i)
	{
		std::unordered_map<std::string, bool> visited;
		if (graph.find(queries[i].first) == graph.end() || graph.find(queries[i].second) == graph.end())
		{
			result.push_back(-1);
			continue;
		}
		double value = 1.0;
		if (dfs(graph, visited, queries[i].first, queries[i].second, value))
			result.push_back(value);
		else
			result.push_back(-1.0);
	}

	return result;
}