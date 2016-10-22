#include<vector>
//��Ŀ����:����һ���������飬һ��������arithmetic���������������ٰ���3��Ԫ�أ�������������Ԫ�صĲ�ֵ��ȣ�
//        ���磬1, 3, 5, 7, 9��arithmetic��1, 1, 2, 5, 7����arithmetic��Ҫ���ҳ��������ж��ٸ�arithmetic
//        ����
//�ⷨ����:��̬�滮�����ڵ�i��Ԫ�أ��ж�ǰ����Ԫ����ɵ������ǲ���arithmetic�ģ�����ǣ�cur��1��֮ǰcur�����
//        ���Ե�i-1��Ԫ��Ϊ�յ��arithmetic���еĸ��������A[i] - A[i - 1] == A[i - 1] - A[i - 2],˵����i
//        ��Ԫ�ؿ��Ժ�֮ǰ��Ԫ����ɸ���������

int numberOfArithmeticSlices(std::vector<int>& A) 
{
	int cur = 0, sum = 0;
	for (int i = 2; i < A.size(); ++i)
	{
		if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) 
		{
			cur += 1;
			sum += cur;
		}
		else 
			cur = 0;
	}
	return sum;
}