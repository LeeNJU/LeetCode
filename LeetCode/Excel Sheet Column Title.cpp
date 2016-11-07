#include<string>
//题目描述:给定一个正整数，返回对应的形式，例如1->A, 2->B, 3->C,..., 26->Z, 27->AA
//解法描述:26进制转换，注意n要减1

std::string convertToTitle(int n) 
{
	int base = 26;
	std::string result = "";
	while (n > 0)
	{
		char c = (n - 1) % base + 'A';
		result = c + result;
		n = (n - 1) / 26;
	}

	return result;
}