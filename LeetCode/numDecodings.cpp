#include<iostream>
#include<string>

using namespace std;

//known bugs for 0

int numDecodings(string s)//总的思路是两两分组，统计有一对的情况
{
    if (s.empty() || (s.length() == 1 && s[0] == '0'))
		return 0;
	if (s.length() == 1)
		return s.length();
	
	int pair = 0, n = 0;//pair记录一对的个数，一对可以相连， n表示不交叉的一对的个数
	int index = 0;
	const int MAX = 26;
	for (int i = 0; i < s.length() - 1; ++i)
	{
		if (atoi(s.substr(i, 2).c_str()) <= MAX)
		{
			if (s[i] != '0')
			{
				++pair;
				if (i == index)
					++n;
				if (i - index > 1)
				{
					++n;
					index = i;
				}
			}
			
		}
	}

	return 0;
}

