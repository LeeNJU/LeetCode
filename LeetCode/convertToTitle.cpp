#include <string>
#include <algorithm>

std::string convertToTitle(int n)//ʮ����ת26����  ���Ҫ��ת
{
	int Base = 26;
	std::string result = "";
	while (n)
	{
		if (n % Base)
		{
			result += n % Base - 1 + 'A';
			n /= Base;
		}
		else
		{
			result += 'Z';
			n = n / Base - 1;
		}
	}
	reverse(result.begin(), result.end());
	return result;
}
