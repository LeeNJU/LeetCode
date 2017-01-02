#include<string>
#include<unordered_map>
#include<algorithm>

//题目描述：给定一个字符串，找出其中最大的没有重复字符的子串的长度。"abcabcbb"的是abc,长度为3，"bbbbb"的是b，长度为1
//解法描述：用两个指针，分别指向当前子串，相当于窗口，遍历字符串，并检查在[i,j]区间里是否有重复元素

int lengthOfLongestSubstring(std::string s)
{
	int length = 0;
	std::unordered_map<char, int> map;
	for (int i = 0, j = 0; j < s.size(); ++j)
	{
		if (map.find(s[j]) != map.end())
		{
			int index = map[s[j]];
			while (i <= index)
				map.erase(s[i++]);
		}
		map[s[j]] = j;
		length = std::max(length, j - i + 1);
	}
	return length;
}