#include<string>
#include<unordered_map>
#include<algorithm>

//题目描述：给定一个字符串，找出其中最大的没有重复字符的子串的长度。"abcabcbb"的是abc,长度为3，"bbbbb"的是b，长度为1
//解法描述：用两个指针，分别指向当前子串，相当于窗口，遍历字符串，并检查在[i,j]区间里是否有重复元素

int lengthOfLongestSubstring(std::string s)
{
	int result = 0;
	for (int i = 0, j = 0; i <= j && j < s.length(); ++j)
	{
		int index = i;
		while (index < j)
		{
			if (s[index] == s[j])
			{
				i = index + 1;
				break;
			}
			++index;
		}
		result = result >= j - i + 1 ? result : j - i + 1;
	}
	return result;
}