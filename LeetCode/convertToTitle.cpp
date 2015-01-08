#include <string>
#include <algorithm>

std::string convertToTitle(int n)//十进制转26进制  最后要反转
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
