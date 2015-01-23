#include<iostream>
#include<string>
#include<algorithm>
//给定两个数字字符串，将这两个字符串按照二进制进行相加，返回结果
//解法：先反转两个字符串，然后两个指针分别遍历两个字符串进行相加

std::string addBinary(std::string a, std::string b)
{
	std::string result;
	const size_t length = a.size() > b.size() ? a.size() : b.size();//长度取最大
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int carry = 0;
	for (size_t i = 0; i < length; ++i)
	{
		const int ai = i < a.size() ? a[i] - '0' : 0;//如果下标超过字符串长度，则用0代替，否则用字符串中的值
		const int bi = i < b.size() ? b[i] - '0' : 0;
		const int value = (ai + bi + carry) % 2;
		carry = (ai + bi + carry) / 2;
		result.insert(result.begin(), value + '0');
	}

	if (carry == 1)//最后的进位
		result.insert(result.begin(), '1');
	return result;
}