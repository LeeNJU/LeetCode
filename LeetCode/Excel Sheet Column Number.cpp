#include <string>
//��Ŀ����:����һ���ַ�����A->1, B->2, C->3,..., Z->26, AA->27, AB->28, ������ַ���ת���ɶ�Ӧ������
//�ⷨ����:��������26����

int titleToNumber(std::string s)//26����,  ע�⣺�ַ�Aת��������1�ķ�ʽ
{
	int result = 0;
	int Base = 26;
	for (int i = 0; i < s.length(); ++i)
		result = result * Base + (s[i] - 'A' + 1);

	return result;
}