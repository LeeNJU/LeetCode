#include<limits.h>
//��Ŀ����������һ�������������������ת��123->321
//�ⷨ����������ȥ���һλ���з�ת��ע�����㣺result���ܻ������Ҫ�����жϣ���ε�x=INT_MINʱҪ��������
int reverse(int x)
{
	if (x == INT_MIN)//����������Ϊ-INT_MIN�����
		return 0;
	int result = 0;
	int value = x > 0 ? x : -x;
	while (value)
	{
		int temp = value % 10;
		if (result > INT_MAX / 10 || (result == INT_MAX / 10 && temp > INT_MAX % 10))//������
			return 0;
		result = result * 10 + temp;
		value /= 10;
	}
	return x > 0 ? result : -result;
}