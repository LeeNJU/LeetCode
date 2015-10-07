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