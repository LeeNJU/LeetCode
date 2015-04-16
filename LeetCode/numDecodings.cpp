#include<string>
#include<vector>
//题目描述：根据如下规则：A->1, B->2,...,Z->26,每个字母对应一个数字，现给定一个数字字符串，将其翻译成字母，求总共有多少的解码方法  "12"可以翻译为AB或者L
//解法描述：动态规划
//bugs
int numDecodings(std::string s)//总的思路是两两分组，统计有一对的情况
{
	if (s.empty() || s[0] == '0')
		return 0;

	std::vector<int> result(s.length() + 2, 0);
	std::string temp = "00" + s;
	result[0] = 0, result[1] = 1;

	for (int i = 2; i < temp.length(); ++i)
	{
		if (temp[i] == '0' && stoi(temp.substr(i - 1, 2)) <= 26)
			result[i] = result[i - 2];
		else if (temp[i] != '0' && stoi(temp.substr(i - 1, 2)) <= 26)
			result[i] = result[i - 1] + result[i - 2];
		else
			result[i] = result[i - 1];
	}
	return result [result.size() - 1];
}

