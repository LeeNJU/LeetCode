#include<string>
//��Ŀ����:����һ���ַ������ж��ַ����ܷ���ĳһ�����ַ����ظ���ζ��õ�������"abab", ���ַ���������"ab"�ظ�
//        ���εõ�������true��"abcabcabcabc"������"abc"�ظ��ĴΣ�����"abcabc"�ظ����εõ�
//�ⷨ����:���ַ�����Ȼ���������ַ���ƴ�Ӷ��ɣ���Ȼ�������һ���ַ���ȵ��ַ���ɨ���ַ���������������һ���ַ�
//        ��ȵ��ַ���˵�����ַ�����������ȷ�����ַ���

bool repeatedSubstringPattern(std::string str) 
{
	for (int i = 1; i < str.size(); ++i)
	{
		if (str[i] == str[0])
		{
			std::string s = str.substr(0, i);
			if ((int) str.size() % (int) s.size() != 0)
				continue;

			std::string res = "";
			int count = (int) str.size() / (int) s.size();
			while (count)
			{
				res += s;
				--count;
			}

			if (res == str)
				return true;
		}
	}
	return false;
}