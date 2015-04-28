#include<vector>
#include<string>
#include<unordered_map>
//题目描述：给定一个字符串s和word list，word都是同样的长度（具体描述看leetcode网站）
//解法描述：用一个map保存每个word的次数，然后暴力求解，两层for循环，

std::vector<int> findSubstring(std::string s, std::vector<std::string>& words)
{
	int wordLength = words[0].length();
	int catLength = wordLength * words.size();
	std::vector<int> result;
	
	if (s.length() < catLength) //特殊情况
		return result;

	std::unordered_map<std::string, int> wordCount;//保存每个word出现的次数
	for (int i = 0; i < words.size(); ++i)
		++wordCount[words[i]];

	for (int i = 0; i <= s.length() - catLength; ++i) 
	{
		std::unordered_map<std::string, int> unused(wordCount);
		for (int j = i; j < i + catLength; j += wordLength) 
		{
			std::unordered_map<std::string, int>::iterator pos = unused.find(s.substr(j, wordLength));//截取一个word，查找是否存在于wordlist中
			if (pos == unused.end() || pos->second == 0) //不存在就直接退出
				break;
			if (--pos->second == 0) //如果存在，就把word的次数减去1，如果等于0，就删除这个word
				unused.erase(pos);
		}
		if (unused.size() == 0) //等于0表示每个词都只用了一次
			result.push_back(i);
	}
	return result;
}