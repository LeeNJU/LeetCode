#include<iostream>
//��Ŀ����������һ��ֻ������ĸ�Ϳո���ַ�����������һ�����ʵĳ��ȣ�����"Hello World"�����һ�����ʳ���Ϊ5
//�ⷨ�������Ӻ�ɨ�裬���ҵ���һ���ǿ��ַ���Ȼ������ǰɨ�裬ֱ������һ���ո�����±����0
int lengthOfLastWord(const char* s)
{
	int length = strlen(s) - 1, result = 0;
	while (s[length] == ' ')//���Ժ���Ŀո��ҵ���һ���ǿ��ַ�
		--length;

	for (; length>= 0; --length)//��ǰɨ�裬ֱ�������ǿո�
	{
		if (s[length] != ' ')
			++result;
		else
			break;
	}

	return result;
}