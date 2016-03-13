#include<string>
#include<vector>
#include<unordered_map>
//题目描述:给定一个字符串数字，如果这些数字翻转180度，判断是否跟原来的数字字符串相等，例如"69",翻转180度后，
//        还是"69"
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

//version2
//题目描述:给定一个n，找到所有长度为n的strobogramatic字符串,例如n=2，返回["11","69","88","96"]
std::vector<std::string> findStrobogrammatic(int n) 
{
	std::vector<std::string> strobos;
	if (n % 2 == 1)//奇数 
		strobos = { "0", "1", "8" };
	else //偶数
		strobos = { "" };
	std::vector<std::string> bases = { "00", "11", "88", "69", "96" };
	int m = bases.size();
	while (n > 1) 
	{
		n -= 2;
		std::vector<std::string> temp;
		for (std::string strobo : strobos)
		{
			for (int i = (n < 2 ? 1 : 0); i < m; i++)//每次把base中的字符串加到开始和结尾
				temp.push_back(bases[i].substr(0, 1) + strobo + bases[i].substr(1));
		}
		swap(temp, strobos);//交换temp来实现递归
	}
	return strobos;
}

//version 3
//题目描述:给定一个range，low和high，找到所有在low<=num<=high的Strobogrammatic Number
//解法描述:类似上一题，在产生的时候，要判断是不是在range之内
bool compare(std::string s1, std::string s2) 
{
	if (s1.length() != s2.length())
		return s1.length() <= s2.length();

	for (int i = 0; i < s1.length(); i++) 
	{
		if (s1[i] < s2[i]) 
			return true;
		else if (s1[i] > s2[i]) 
			return false;
	}

	return true;
}

int strobogrammaticInRange(const std::vector<std::pair<char, char>>& nums, const std::string& low, const std::string& high, std::string t, int count) 
{
	if (high.length() < t.length())
		return count;
	if (compare(low, t) && compare(t, high))
	{
		if (t.length() == 1 || t.length() > 1 && t.front() != '0')
			++count;
	}

	for (auto iter = nums.begin(); iter != nums.end(); ++iter)
		count = strobogrammaticInRange(nums, low, high, std::string(1, iter->first) + t + std::string(1, iter->second), count);

	return count;
}

int strobogrammaticInRange(std::string low, std::string high)
{
	if (!compare(low, high))
		return 0;

	std::vector<std::pair<char, char>> nums = { { '0', '0' }, { '1', '1' }, { '6', '9' }, { '8', '8' }, { '9', '6' } };

	int count = strobogrammaticInRange(nums, low, high, "", 0);
	count = strobogrammaticInRange(nums, low, high, "0", count);
	count = strobogrammaticInRange(nums, low, high, "1", count);
	count = strobogrammaticInRange(nums, low, high, "8", count);

	return count;
}