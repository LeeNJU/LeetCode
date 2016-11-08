#include<string>
#include<sstream>
#include<algorithm>
#include<functional>
//题目描述：求出第n个count-and-say序列，1,11,21,1211,111221，……
//n=1时，读作1个1，所以是1，n=2时，看前一个序列，读作1个1，所以是11，n=3时，看前一个序列，读作2个1，所以是21，……
//解法描述：扫描计数

std::string countAndSay(int n)
{
	std::string s("1");

	while (--n)//直到寻找到第n个序列为止
	{
		std::stringstream ss;
		for (std::string::iterator iter = s.begin(); iter != s.end();)
		{
			std::string::iterator iters = std::find_if(iter, s.end(), std::bind1st(std::not_equal_to<char>(), *iter));//扫描计数，找到第一个不等于当前字符的位置，这样就可以计算出个数
			ss << distance(iter, iters) << *iter;
			iter = iters;
		}
		s = ss.str();
	}
	return s;
}

//my version
/*
std::string countAndSay(int n)
{
	if (n == 1)
		return "1";

	std::string prev = "1", cur = "", result;
	for (int i = 2; i <= n; ++i)
	{
		int count = 1;
		for (int j = 1; j < prev.size(); ++j)
		{
			if (prev[j] == prev[j - 1])
				++count;
			else
			{
				cur += std::string(1, count + '0');
				cur.push_back(prev[j - 1]);
				count = 1;
			}
		}
		cur += std::string(1, count + '0');
		cur.push_back(prev[prev.size() - 1]);

		prev = cur;
		result = cur;
		cur = "";
	}
	return result;
}*/