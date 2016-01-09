#include<string>
#include<vector>
//题目描述:给定一个字符串只包含+和0，现在把连续的两个++变成两个连续的--，求最后会得到多少种结果
//解法描述:扫描一遍
std::vector<std::string> generatePossibleNextMoves(std::string s) 
{
	std::vector<std::string> moves;
	for (int i = 0; i < s.size() - 1; ++i) 
	{
		if (s[i] == '+' && s[i + 1] == '+') 
		{
			s[i] = s[i + 1] = '-';
			moves.push_back(s);
			s[i] = s[i + 1] = '+';
		}
	}
	return moves;
}