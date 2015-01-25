#include<iostream>
//题目描述：实现strStr，从字符串haystack中找到字符串needle第一次出现的位置，返回下标
//解法：暴力解法，
int strStr(char *haystack, char *needle)
{
	if (!*needle)//判断needle是否为空串，若是，直接返回0
		return 0;

	int lengthA = strlen(haystack), lengthB = strlen(needle);
	for (int i = 0; i <= lengthA - lengthB; ++i)//注意是小于等于号,遍历字符串haystack
	{
		if (haystack[i] == needle[0])//如果第一个字符相等，则循环判断是否相等
		{
			int index = i, j = 0;
			for (; index < lengthA && j < lengthB; ++index, ++j)
			{
				if (haystack[index] != needle[j])
					break;
			}
			if (j == lengthB)//判断是否是正确街
				return i;
		}
	}
	return -1;
}