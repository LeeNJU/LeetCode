#include<iostream>
#include<string>

using namespace std;

//known bugs for 0

int numDecodings(string s)//�ܵ�˼·���������飬ͳ����һ�Ե����
{
    if (s.empty() || (s.length() == 1 && s[0] == '0'))
		return 0;
	if (s.length() == 1)
		return s.length();
	
	int pair = 0, n = 0;//pair��¼һ�Եĸ�����һ�Կ��������� n��ʾ�������һ�Եĸ���
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

int main()
{
	string s("111");
	cout << numDecodings(s) << endl;
}