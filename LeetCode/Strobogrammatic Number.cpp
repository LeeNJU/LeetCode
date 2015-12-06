#include<string>
#include<unordered_map>
//题目描述:给定一个字符串数字，如果这些数字翻转180度，判断是否跟原来的数字字符串相等，例如"69",翻转180度后，还是"69"
//解法描述:两个指针往中间走，两边翻转之后必须相等
bool isStrobogrammatic(std::string num) 
{
	std::unordered_map<char, char> m;
	m['0'] = '0';//只有这些字符翻转180度后还是一个数字
	m['1'] = '1';
	m['6'] = '9';
	m['8'] = '8';
	m['9'] = '6';

	for (int i = 0, j = num.length() - 1; i <= j; ++i, --j)
	{
		if (m.find(num[i]) == m.end() || m[num[i]] != num[j])//如果当前字符不在map里面或者左右不等
			return false;
	}
	return true;
}