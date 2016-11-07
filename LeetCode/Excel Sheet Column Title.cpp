#include<string>
//��Ŀ����:����һ�������������ض�Ӧ����ʽ������1->A, 2->B, 3->C,..., 26->Z, 27->AA
//�ⷨ����:26����ת����ע��nҪ��1

std::string convertToTitle(int n) 
{
	int base = 26;
	std::string result = "";
	while (n > 0)
	{
		char c = (n - 1) % base + 'A';
		result = c + result;
		n = (n - 1) / 26;
	}

	return result;
}