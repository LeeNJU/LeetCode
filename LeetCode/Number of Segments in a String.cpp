#include<string>
//��Ŀ����:����һ���ַ������ַ����е��ַ��ÿո����������ٸ��������ַ�������"Hello, my name is John"���ܹ���
//        5�����ո�������ַ���
//�ⷨ����:���Կ�ͷ�Ŀո�ע���м������Ŀո�

int countSegments(std::string s) 
{
	int count = 0;
	int index = 0;
	while (index < s.size() && s[index] == ' ')//ȥ��leading�Ŀո�
		++index;

	if (index >= s.size())//ȫ�ǿո�
		return 0;

	for (; index < s.size(); ++index)//ע�������Ŀո�
	{
		if (s[index] == ' ' && s[index - 1] != ' ')
			++count;
	}

	if (s.back() != ' ')
		++count;
	return count;
}