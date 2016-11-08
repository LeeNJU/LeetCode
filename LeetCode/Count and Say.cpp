#include<string>
#include<sstream>
#include<algorithm>
#include<functional>
//��Ŀ�����������n��count-and-say���У�1,11,21,1211,111221������
//n=1ʱ������1��1��������1��n=2ʱ����ǰһ�����У�����1��1��������11��n=3ʱ����ǰһ�����У�����2��1��������21������
//�ⷨ������ɨ�����

std::string countAndSay(int n)
{
	std::string s("1");

	while (--n)//ֱ��Ѱ�ҵ���n������Ϊֹ
	{
		std::stringstream ss;
		for (std::string::iterator iter = s.begin(); iter != s.end();)
		{
			std::string::iterator iters = std::find_if(iter, s.end(), std::bind1st(std::not_equal_to<char>(), *iter));//ɨ��������ҵ���һ�������ڵ�ǰ�ַ���λ�ã������Ϳ��Լ��������
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