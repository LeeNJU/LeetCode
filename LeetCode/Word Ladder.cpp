#include<vector>
#include<string>
#include<unordered_set>
#include<queue>
//题目描述:给定一个起始单词，一个终止单词和一个字典，每次把起始单词变换一个字符，把起始单词变换成终止单词，
//        其中每次变换得到的中间过渡单词必须在字典中能够找到，求最小的变换次数
//解法描述:广度优先遍历，用队列，依次用a到z去代替起始单词的每个元素，判断得到的中间单词是否在字典中，如果在，
//        加入到队列中，其中要注意记录单词的层数

int ladderLength(std::string beginWord, std::string endWord, std::unordered_set<std::string>& wordDict)
{
	std::queue<std::pair<std::string, int>> que;
	que.push(std::pair<std::string, int>(beginWord, 1)); //记录每个单词以及对应的层数
	while (!que.empty())
	{
		std::pair<std::string, int> word = que.front();
		que.pop();
		if (word.first == endWord) //找到目标单词了
			return word.second;

		for (int i = 0; i < word.first.size(); ++i)
		{
			char temp = word.first[i];
			for (int j = 'a'; j <= 'z'; ++j) //分别用a到z去替换，在字典中查找是否存在该单词
			{
				word.first[i] = j;
				if (wordDict.find(word.first) != wordDict.end())
				{
					que.push(std::pair<std::string, int>(word.first, word.second + 1));
					wordDict.erase(word.first);//找到该单词，在字典中删除
				}
			}
			word.first[i] = temp; //恢复单词
		}
	}
	return 0;
}