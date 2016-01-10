#include<unordered_map>
#include<vector>
//题目描述:给定两个字符串，判断这两个字符串是不是同一个模式。例如：pattern = "abba", str = "dog cat cat dog" 
//         应该返回true
//解法描述:用hashtbale存每个元素对应的下标，然后判断对应的下标是否相等
bool wordPattern(std::string pattern, std::string str) 
{
	std::unordered_map<char, std::vector<int>> p;
	std::unordered_map<std::string, std::vector<int>> s;
	std::vector<std::string> st; //保存str里面的word，用这个数组来寻找每个word在patter字符串里对应的字符
	for (int i = 0; i < pattern.size(); ++i)//用hashtable存入每个元素对应的下标
		p[pattern[i]].push_back(i);

	std::string word;
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] != ' ')
			word += str[i];
		else
		{
			st.push_back(word);
			s[word].push_back(st.size() - 1);
			word = "";
		}
	}

	if (word != "")//注意这里
	{
		st.push_back(word);
		s[word].push_back(st.size() - 1);
	}

	if (st.size() != pattern.size())//大小必须得一样
		return false;

	for (int i = 0; i < st.size(); ++i)//遍历每一个word，找到对应的字符串，并比较其对应的下标是否一样
	{
		char corresponding = pattern[i];
		if (p[corresponding] != s[st[i]])
			return false;
	}
	return true;
}


//version 2
//题目描述:s字符串不再用空格隔开，然后判断pattern和s是不是同一个模式，能不能进行匹配
//解法描述:回溯法，逐个尝试
bool dfs(const std::string& pattern, int pindex, const std::string& s, int sindex, std::unordered_map<char, std::string>& m)
{
	if (pindex == pattern.size())
		return sindex == s.size();

	if (sindex == s.size())
		return false;

	if (m.find(pattern[pindex]) != m.end())//当前要匹配的字符之前已经出现过，就与之前对应的字符串比较
	{
		std::string str = m[pattern[pindex]];
		if (str.size() > s.size() - sindex || s.substr(sindex, str.size()) != str)
			return false;
		return dfs(pattern, pindex + 1, s, sindex + str.size(), m);
	}
	else//当前的字符在之前没有出现过
	{
		for (int i = sindex; i < s.size(); ++i)
		{
			std::string sub = s.substr(sindex, i - sindex + 1);
			bool exist = false;
			auto iter = m.begin();
			while (iter != m.end())//这里判断字符串sub是不是在之前被匹配过
			{
				if (iter->second == sub)
				{
					exist = true;
					break;
				}
			}

			if (exist)//之前被匹配过
				continue;

			m[pattern[pindex]] = sub;
			if (dfs(pattern, pindex + 1, s, i + 1, m))
				return true;
			m.erase(pattern[pindex]);
		}
	}
	return false;
}

bool wordPatternMatch(std::string pattern, std::string str)
{
	std::unordered_map<char, std::string> mp;
	return dfs(pattern, 0, str, 0, mp);
}