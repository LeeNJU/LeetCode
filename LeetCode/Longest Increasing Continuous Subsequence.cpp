#include<vector>
#include<algorithm>

//��Ŀ����:����һ�����飬�ҵ�������������������������ݼ��������飬����[5, 4, 2, 1, 3]���������������
//        �ݼ�����������[5, 4, 2, 1],������4
//�ⷨ����:ɨ�����ߣ��ȴ������ҵõ������ݼ��������飬Ȼ���������õ����������������顣
int longestIncreasingContinuousSubsequence(std::vector<int>& A) 
{
	if (A.empty())
		return 0;

	int left_max = 1;
	int left_length = 1; //lengthΪ������ǰԪ�صĳ��ȣ�maxΪȫ�����ֵ
	for (int i = 1; i < A.size(); ++i)//�������ҵõ������ݼ���������
	{
		if (A[i] < A[i - 1])
		{
			++left_length;
			left_max = std::max(left_max, left_length);
		}
		else
			left_length = 1;
	}

	int right_max = 1;
	int right_length = 1;
	for (int i = A.size() - 2; i >= 0; --i)//��������õ�����������������
	{
		if (A[i] < A[i + 1])
		{
			++right_length;
			right_max = std::max(right_max, right_length);
		}
		else
			right_length = 1;
	}

	return std::max(left_max, right_max);
}