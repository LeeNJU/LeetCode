#include <string>
int titleToNumber(std::string s)//26����,  ע�⣺�ַ�Aת��������1�ķ�ʽ
{
	int result = 0;
	int Base = 26;
	for (int i = 0; i < s.length(); ++i)
	{
		result = result * Base + (s[i] - 'A' + 1);
	}
	return result;
}