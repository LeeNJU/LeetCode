#include<string>
#include<algorithm>
//��Ŀ����������һ���ַ���s���ҵ��������Ļ����Ӵ�
//�ⷨ���������������оٻ����Ӵ��������ַ���������������չ,Ҫע���������Ĵ���ż�����Ĵ�������

int expandAroundCenter(const std::string& s, int left, int right)
{
	while (left >= 0 && right < s.length() && s[left] == s[right])//����������
	{
		--left;
		++right;
	}
	return right - left - 1;
}

std::string longestPalindrome(std::string s)
{
	int maxLength = 1, index = 0;//��¼��󳤶ȺͿ�ʼ���±�
	for (int i = 0; i < s.length(); ++i)
	{
		int length = 0;
		length = expandAroundCenter(s, i, i);//�ж��������Ĵ�
		if (length > maxLength)
		{
			maxLength = length;
			index = i - length / 2;
		}

		length = expandAroundCenter(s, i, i + 1);//�ж�ż�����Ĵ�
		if (length > maxLength)
		{
			maxLength = length;
			index = i - length / 2 + 1;
		}
	}
	return s.substr(index, maxLength);
}