#include<unordered_map>
#include<string>
#include<vector>
//��Ŀ����:����һ��A / B = k�ı��ʽ����ʾA��B֮��ı�����ϵ��Ȼ�����һ��C / D��ʽ��query�����C��D֮���
//        ������ϵ���������a / b = 2.0, b / c = 3.0�������Щquery��ֵ
//        a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
//�ⷨ����:��ͼ����ʾ������ϵ��Ȼ���query����ʼ�ַ�����ʼ����

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