#include<iostream>
//题目描述：给定一个只包含字母和空格的字符串，求出最后一个单词的长度，例如"Hello World"的最后一个单词长度为5
//解法描述：从后扫描，先找到第一个非空字符，然后再往前扫描，直到碰到一个空格或者下标等于0
int lengthOfLastWord(const char* s)
{
	int length = strlen(s) - 1, result = 0;
	while (s[length] == ' ')//忽略后面的空格，找到第一个非空字符
		--length;

	for (; length>= 0; --length)//向前扫描，直到碰到非空格
	{
		if (s[length] != ' ')
			++result;
		else
			break;
	}

	return result;
}