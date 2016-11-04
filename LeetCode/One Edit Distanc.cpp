#include<string>
//题目描述:给定两个字符串，判断这两个字符串的编辑距离是不是1
//解法描述:首先长度差不能超过1，如果长度相同，最多只能有一个不同的字符，如果长度差为1，最多有一个字符不同,其余
//        字符必须一样
bool isOneDifL(std::string s, std::string t)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == t[i])
			continue;
		return s.substr(i) == t.substr(i + 1);
	}
	return true; // 说明前面的都相等只有最后一个不匹配
}
bool isSameLen(std::string s, std::string t)//长度相等，最多有一个不同的字符
{
	int count = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != t[i])
			++count;
	}
	return count == 1;
}
bool isOneEditDistance(std::string s, std::string t)
{
	if (std::abs(static_cast<int>(s.size()) - static_cast<int>(t.size())) > 1) //长度差超过1
		return false;
	if (s.size() == t.size()) //长度相等，最多有一个不同的字符
		return isSameLen(s, t);
	else if (s.size() < t.size()) //长度相差1，那么长的字符串比短的字符串多一个字符，其余的字符必须相同
		return isOneDifL(s, t);
	else 
		return isOneDifL(t, s);
}