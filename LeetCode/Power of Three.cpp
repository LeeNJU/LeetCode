#include<cmath>
#include<algorithm>
//��Ŀ����:����һ����n���ж�n�ǲ���3����
//�ⷨ����:���ϳ���3��ֱ������1���߲��ܱ�3����,����������ѧ�������ҵ�int����������3���ݣ�Ȼ������ݶ�n����
//        ȡģ�����n��3���ݣ�ȡģ�Ľ��һ����0.

bool isPowerOfThree(int n) 
{
	if (n <= 0) 
		return false;
	int t = pow(3, (int) (log(INT_MAX) / log(3))); //t������3����
	return (t % n == 0);
}