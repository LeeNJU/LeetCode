#include<string>
//题目描述：给定一个排序的字符数组和一个字符，在数组中找到第一个严格大于这个字符的字符。如果数组中不存在这个字符，返回
//         数组中的最小元素
//解法描述：二分查找，如果s[middle]比a大，那么记录result，然后继续二分查找

char smallestCharacter(std::string& s, char a)
{
	int left = 0, right = s.size() - 1, middle = 0;
	char result = s[0];
	while (left <= right)
	{
		middle = left + (right - left) / 2;
		if (s[middle] > s[a])
		{
			result = s[middle];
			right = middle - 1;
		}
		else
			left = middle + 1;
	}
	return result;
}