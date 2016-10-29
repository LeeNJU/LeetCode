#include<string>
#include<vector>
#include<unordered_set>
#include<queue>
//题目描述:给定一个字符串表示基因，每次可以把一个基因变成另一个基因，求最少需要多少步把一个字符串基因变成另
//        一个字符串基因，例如start:"AACCGGTT", end:"AACCGGTA", bank:["AACCGGTA"],只需要一步就可以把start
//        字符串变成end字符串，变换过程中的字符串必须在bank中
//解法描述:广搜，类似于word ladder

int minMutation(std::string start, std::string end, std::vector<std::string>& bank) 
{
	std::unordered_set<std::string> set(bank.begin(), bank.end());
	std::unordered_set<std::string> visited;//已经访问过的字符串
	std::queue<std::pair<std::string, int>> queue;
	queue.push(std::pair<std::string, int>(start, 0));

	while (!queue.empty())
	{
		std::pair<std::string, int> pair = queue.front();
		queue.pop();

		if (pair.first == end)
			return pair.second;

		visited.insert(pair.first);
		std::string genes = "ACGT";
		std::string s = pair.first;
		for (int i = 0; i < s.size(); ++i)
		{
			char original = s[i];
			for (char c : genes)
			{
				if (c == original)
					continue;

				s[i] = c;
				if (set.find(s) != set.end() && visited.find(s) == visited.end())
					queue.push(std::pair<std::string, int>(s, pair.second + 1));
			}
			s[i] = original;
		}
	}
	return -1;
}