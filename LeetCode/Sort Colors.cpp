#include<iostream>
#include<algorithm>
//����һ�����飬����0,1,2��������������򣬲���ʹ��sort����
//�ⷨ����˫ָ�룬һ��ָ��ָ��ͷ��[0,red - 1]��ʾȫ��0�� һ��ָ��ָ����棬[blue + 1, n - 1]��ʾȫ��2�� �м�Ϊ1��ѭ���������飬��2���󽻻�����0��ǰ���������Ӷ�ΪO(n)
//ע�⣺��������Ԫ��֮�󣬲��ܽ���++i����Ϊ�������Ԫ�ؿ�����ͬ
void sortColors(int A[], int n)
{
	int red = 0, blue = n - 1;
	for (int i = 0; i < blue + 1;)//i�ķ�Χֻ��Ҫ��blue+1����
	{
		if (A[i] == 2)
			std::swap(A[i], A[blue--]);
		else if (A[i] == 0)
			std::swap(A[i++], A[red++]);//������ע������A[i++]
		else
			++i;
	}
}
