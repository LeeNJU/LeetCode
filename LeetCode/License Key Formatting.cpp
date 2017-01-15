#include<string>
//题目描述:给定一个字符串表示license key，中间用-分隔，对字符串进行格式化，使得每一部分都包含K个字符，每一部分
//        用-分隔，例如S = "2-4A0r7-4k", K = 4，重新格式化之后为"24A0-R74K"，第一部分不一定包含K个字符
//解法描述:倒序扫描，忽略-，记录每一部分的字符个数，等于K的时候插入-

std::string licenseKeyFormatting(std::string S, int K) 
{
	std::string result;
	int count = 0;
	for (int i = S.size() - 1; i >= 0; --i)
	{
		if (S[i] == '-')
			continue;

		if (count == K)
		{
			result = "-" + result;
			count = 0;
		}

		S[i] = toupper(S[i]);
		result = S[i] + result;
		++count;
	}
	return result;
}