#include<vector>
//��Ŀ����:����һ�����飬�ҵ�һ�����䣬ʹ��������ĺ����
//�ⷨ����:�ֲ����ȫ�����Ž⣬����ֲ����Ž��sum�����䣬Ȼ�����ȫ�����Ž������
std::vector<int> continuousSubarraySum(std::vector<int>& A) 
{
	std::vector<int> result(2, 0);//result����ȫ�����Ž������
	if (A.empty())
		return result;

	int local_sum = A[0], local_left = 0, local_right = 0;//����ֲ����Ž��sum������
	int global_sum = A[0];
	for (int i = 1; i < A.size(); ++i)
	{
		if (local_sum + A[i] <= A[i])//���¾ֲ����Ž��sum������
		{
			local_sum = A[i];
			local_left = i;
			local_right = i;
		}
		else
		{
			local_sum += A[i];
			local_right = i;
		}

		if (local_sum >= global_sum)//����ȫ�����Ž������
		{
			global_sum = local_sum;
			result[0] = local_left;
			result[1] = local_right;
		}

	}
	return result;
}