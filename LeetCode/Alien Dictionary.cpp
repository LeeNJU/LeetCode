#include<string>
#include<unordered_map>
#include<vector>
#include<queue>
#include<unordered_set>
#include<algorithm>
//��Ŀ����:����һ���ַ������飬������ַ�������һ��˳�����У��ҵ���Щ�ַ��������˳������["wrt","wrf","er",
//        "ett","rftt"]����ô�ַ������˳����"wertf"
//�ⷨ����:������ʵ����ͼ���ַ�֮������˳�����һ������ߣ��ȹ���һ��ͼ��Ȼ���ù����ж��Ƿ��л�

std::unordered_map<char, std::unordered_set<char>> build_graph(std::vector<std::string>& words) 
{                            //���ڽӱ�ķ�ʽ����һ��ͼ
	std::unordered_map<char, std::unordered_set<char>> graph;
	int n = words.size();
	for (int i = 1; i < n; i++) 
	{
		bool found = false;
		std::string word1 = words[i - 1];
		std::string word2 = words[i];
		int m = word1.length(), n = word2.length(), l = std::max(m, n);
		for (int j = 0; j < l; j++) //�����ַ���ֻ��ȷ�������ַ�֮��Ĺ�ϵ��Ҳ����ͼ�еı�
		{
			if (j < m && graph.find(word1[j]) == graph.end())//ȷ����ÿ���㶼�ӵ��ڽӱ���
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
{                                     //����ÿ��������
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
	std::queue<char> q;//���ù���
	for (auto node : degrees)//ѡ�����Ϊ0�ĵ�
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
			if (!--degrees[neighbor])//���Ϊ0���������
				q.push(neighbor);
		}
	}
	return result;
}