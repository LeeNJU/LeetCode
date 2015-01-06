#include <string>
int titleToNumber(std::string s)//26进制,  注意：字符A转换成数字1的方式
{
	int result = 0;
	int Base = 26;
	for (int i = 0; i < s.length(); ++i)
	{
		result = result * Base + (s[i] - 'A' + 1);
	}
	return result;
}