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

//version 2
//题目描述:给定一个字符串只包含+和-，两个人轮流把连续的+变成-，经过变换后，如果没有连续的++，那么该人获胜，判断该人是否获胜
//解法描述:递归，遍历所有的解
bool canWin(std::string s) 
{
	for (int i = -1; (i = s.find("++", i + 1)) >= 0;)//找到一个连续的++
	{
		if (!canWin(s.substr(0, i) + '-' + s.substr(i + 2)))//把连续的++变成-，然后递归判断
			return true;
	}
	return false;
}