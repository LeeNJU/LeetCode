#include<string>
#include<unordered_map>
#include<vector>
#include<queue>
#include<unordered_set>
#include<algorithm>
//题目描述:给定一个字符串数组，里面的字符串按照一定顺序排列，找到这些字符串的相对顺序，例如["wrt","wrf","er",
//        "ett","rftt"]，那么字符的相对顺序是"wertf"
//解法描述:本质其实就是图，字符之间的相对顺序就是一条有向边，先构造一个图，然后用广搜判断是否有环

std::unordered_map<char, std::unordered_set<char>> build_graph(std::vector<std::string>& words) 
{                            //用邻接表的方式建立一个图
	std::unordered_map<char, std::unordered_set<char>> graph;
	int n = words.size();
	for (int i = 1; i < n; i++) 
	{
		bool found = false;
		std::string word1 = words[i - 1];
		std::string word2 = words[i];
		int m = word1.length(), n = word2.length(), l = std::max(m, n);
		for (int j = 0; j < l; j++) //两个字符串只能确定两个字符之间的关系，也就是图中的边
		{
			if (j < m && graph.find(word1[j]) == graph.end())//确保把每个点都加到邻接表里
				graph[word1[j]] = std::unordered_set<char>();
			if (j < n && graph.find(word2[j]) == graph.end())
				graph[word2[j]] = std::unordered_set<char>();
			if (j < m && j < n && word1[j] != word2[j] && !found) 
			{
				graph[word1[j]].insert(word2[j]);
				found = true;
			}
		}
	}
	return graph;
}

std::unordered_map<char, int> compute_indegree(std::unordered_map<char, std::unordered_set<char>>& graph) 
{                                     //计算每个点的入度
	std::unordered_map<char, int> degrees;
	for (auto node : graph)
	{
		for (char neighbor : node.second)
			++degrees[neighbor];
	}
	return degrees;
}

std::string alienOrder(std::vector<std::string>& words) 
{
	if (words.size() == 1) 
		return words[0];
	std::unordered_map<char, std::unordered_set<char>> graph = build_graph(words);
	std::unordered_map<char, int> degrees = compute_indegree(graph);

	std::string result;
	std::queue<char> q;//利用广搜
	for (auto node : degrees)//选出入度为0的点
	{
		if (!node.second)
			q.push(node.first);
	}

	for (int i = 0; i < degrees.size(); ++i)
	{
		if (q.empty())
			return "";

		char c = q.front();
		q.pop();
		result += c;
		for (char neighbor : graph[c])
		{
			if (!--degrees[neighbor])//入度为0，加入队列
				q.push(neighbor);
		}
	}
	return result;
}