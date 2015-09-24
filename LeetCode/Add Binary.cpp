#include<iostream>
#include<string>
#include<algorithm>
//题目描述：给定两个数字字符串，将这两个字符串按照二进制进行相加，返回结果
//解法描述：两个指针分别逆序遍历两个字符串进行相加，最后把结果反转

std::string addBinary(std::string a, std::string b)
{
	std::string result;
	int carry = 0;
	for (int i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0; --i, --j)
	{
		const int ai = i < 0 ? 0 : a[i] - '0';
		const int bi = j < 0 ? 0 : b[j] - '0';
		const int value = (ai + bi + carry) % 2;
		carry = (ai + bi + carry) / 2;
		result.push_back(value + '0');
	}
	if (carry == 1)//最后的进位
		result.push_back('1');
	reverse(result.begin(), result.end());
	return result;
}