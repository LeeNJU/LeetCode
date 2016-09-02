#include<string>
#include<unordered_map>

//题目描述:给定两个字符串，判断他们是不是isomorphic的，例如paper可以被title替换，返回true，egg可以被add替换
//        返回true
//解法描述:用hashtable保存s到t的映射关系，检查s是不是映射到t，再检查t是不是映射到s

bool isIsomorphic(std::string s, std::string t)
{
	if (s.length() != t.length())
		return false;

	std::unordered_map<char, char> mp;
	for (int i = 0; i < s.length(); ++i) 
	{
		if (mp.find(s[i]) == mp.end()) //保存是s[i]到t[i]的映射
			mp[s[i]] = t[i];
		else if (mp[s[i]] != t[i]) //判断当前s[i]是不是映射到t[i]
			return false;
	}

	mp.clear();//反过来检查t是不是映射到s，因为可能s中的多个元素映射到t中的同一个元素，所以要检查t是不是映射到s
	for (int i = 0; i < s.length(); ++i) //例如paher和title，p和h同时映射到t
	{
		if (mp.find(t[i]) == mp.end()) 
			mp[t[i]] = s[i];
		else if (mp[t[i]] != s[i]) 
			return false;
	}
	return true;
}