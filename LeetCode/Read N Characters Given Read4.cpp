#include<algorithm>
//��Ŀ����:����read4�������ú���ÿ�ζ�ȡ4���ַ��������ض�ȡ���ַ����������ֻ��3���ַ�����ֻ��3���ַ���������
//        3��Ҫ��ʵ��read������ȡn���ַ�
//�ⷨ����:ÿ�ε���read4��nҪ��4
int read4(char* buf);
int read(char *buf, int n) 
{
	int res = 0;
	while (n > 0) 
	{
		int tmp = std::min(read4(buf), n);
		res += tmp;
		buf += tmp;
		if (tmp < 4)
			break;
		n -= 4;
	}
	return res;
}