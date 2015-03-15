#include<string>
#include<unordered_map>
#include<algorithm>

//题目描述：给定一个字符串，找出其中最大的没有重复字符的子串的长度。"abcabcbb"的是abc,长度为3，"bbbbb"的是b，长度为1
//解法描述：用两个指针，分别指向当前子串，相当于窗口，用hashtable表示子串中出现过的元素，如果当前元素没有重复，j加1，如果重复了，重复出现的位置为i，那么
//左边指针的位置为i+1，同时要删去hashtable中的部分元素，只保留i+1到j的元素   bugs

int lengthOfLongestSubstring(std::string s)
{
	int result = 0;
	std::unordered_map<char, int> m;

	for (int i = 0, j = 0; j < s.length();)
	{
		std::unordered_map<char, int>::iterator iter = m.find(s[j]);
		if (iter == m.end())//元素没有重复
		{
			m[s[j]] = j;
			++j;
		}
		else
		{
			int index = iter->second + 1;
			m.erase(m.begin(), );
			i = index;
		}
		result = result > j - i ? result : j - i;
	}

	return result;
}