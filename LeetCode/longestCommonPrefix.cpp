#include<string>
#include<vector>
//题目描述：给定一个字符串数组，找到这些字符串中最长的公共前缀
//解法描述：以第一个字符串为标本，逐一比较每个字符串的第一个元素是否相等，再比较第二个元素是否相等
std::string longestCommonPrefix(std::vector<std::string> &strs)
{
	if (strs.empty())
		return "";

	for (int i = 0; i < strs[0].size(); ++i)
	{
		for (int j = 1; j < strs.size(); ++j)
		    if (strs[j][i] != strs[0][i])
				return strs[0].substr(0, i);
	}
	return strs[0];
}