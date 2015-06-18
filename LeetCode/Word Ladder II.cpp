#include<vector>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<queue>

//题目描述：给定一个起始单词，一个终止单词和一个字典，每次把起始单词变换一个字符，把起始单词变换成终止单词，其中每次变换得到的中间过渡单词必须在字典
//         中能够找到，求出合格的变换序列
//解法描述：广度优先遍历，用队列，依次用a到z去代替起始单词的每个元素，判断得到的中间单词是否在字典中，如果在，加入到队列中，其中要注意记录单词的层数

void dfs(std::vector<std::vector<std::string>>& result, std::vector<std::string> intermediate, const std::string& start, const std::string& end, std::unordered_map<std::string, std::vector<std::string>>& dict)
{
	if (start == end)
	{
		result.push_back(intermediate);
		return;
	}

	for (int i = 0; i < dict[start].size(); ++i)
	{
		intermediate.insert(intermediate.begin(), dict[start][i]);
		dfs(result, intermediate, dict[start][i], end, dict);
		intermediate.erase(intermediate.begin());
	}
}

std::vector<std::vector<std::string>> findLadders(std::string start, std::string end, std::unordered_set<std::string> &dict)
{
	std::vector<std::vector<std::string>> result;
	std::queue<std::string> que;
	std::unordered_map<std::string, std::vector<std::string>> prev; //记录每个单词的父节点
	que.push(start);
	prev[start] = std::vector<std::string>();
	bool found = false; //判断是否有解
	dict.erase(start);
	while (!que.empty())
	{
		std::string word = que.front();
		que.pop();
		if (word == end)
			found = true;

		std::string prevWord = word;
		for (int i = 0; i < word.size(); ++i)
		{
			char temp = word[i];
			for (int j = 'a'; j <= 'z'; ++j) //分别用a到z去替换，在字典中查找是否存在该单词
			{
				if (word[i] == static_cast<char>(j))
					continue;
				word[i] = j;
				if (dict.find(word) != dict.end())
				{
					que.push(word);
					prev[word].push_back(prevWord);
				}
			}
			word[i] = temp; //恢复单词
		}
	}
	if (found)
	{
		std::vector<std::string> intermediate;
		intermediate.push_back(end);
		dfs(result, intermediate, end, start, prev);
	}
	return result;
}