#include<algorithm>
//��Ŀ����:����read4�������ú���ÿ�ζ�ȡ4���ַ��������ض�ȡ���ַ����������ֻ��3���ַ�����ֻ��3���ַ���������
//        3��Ҫ��ʵ��read������ȡn���ַ�
//�ⷨ����:ÿ�ε���read4��nҪ��4
int read4(char* buf);
int read(char *buf, int n) 
{
	int result = 0;
	int value = n;
	while (value > 0) 
	{
		int cur = read4(buf + result);
		if (cur == 0) 
			break;
		result += cur;
		value -= cur;
	}
	return std::min(result, n);
}