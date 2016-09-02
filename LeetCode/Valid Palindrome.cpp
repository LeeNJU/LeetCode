#include<string>
#include<cctype>
//��Ŀ����������һ���ַ���(ֻ�������ֺ���ĸ)���ж����Ƿ��ǻ��Ĵ������Դ�Сд
//�ⷨ������ͷβָ�����м�ƽ�������Ҫ���Կո�����

bool isPalindrome(std::string s)
{
	int first = 0, last = s.length() - 1;
	while (first <= last)
	{
		if (!isalnum(s[first]))//�ж��Ƿ�Ϊ�ո�
			++first;
		else if (!isalnum(s[last]))//�ж��Ƿ�Ϊ�ո�
			--last;
		else
		{
			if (tolower(s[first]) != tolower(s[last]))//ignore case
				return false;
			else
			{
				++first;
				--last;
			}
		}
	}
	return true;
}