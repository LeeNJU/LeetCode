#include <string>
//题目描述:给定一个字符串，A->1, B->2, C->3,..., Z->26, AA->27, AB->28, 把这个字符串转换成对应的数字
//解法描述:本质上是26进制

int titleToNumber(std::string s)//26进制,  注意：字符A转换成数字1的方式
{
	int result = 0;
	int Base = 26;
	for (int i = 0; i < s.length(); ++i)
		result = result * Base + (s[i] - 'A' + 1);

	return result;
}