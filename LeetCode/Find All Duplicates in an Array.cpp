#include<vector>
//��Ŀ����:����һ�����飬�����Ԫ�ط�Χ��1��n��n�������С���е�Ԫ�س���һ�Σ��е�Ԫ�س������Σ��ҵ���������
//        ������Ԫ�أ�����[4,3,2,7,8,2,3,1]���������ε�Ԫ����2��3
//�ⷨ����:ɨ�����飬�ѵ�ǰԪ�طŵ����ʵ�λ�ã������ǰԪ��Ϊval��Ӧ�ð�val�ŵ��±�Ϊval - 1��λ�ã���val - 1
//        ��Ԫ����Ϊ��������ʾ��Ԫ���Ѿ����ֹ���

std::vector<int> findDuplicates(std::vector<int>& nums) 
{
	std::vector<int> result;
	for (int i = 0; i < nums.size(); ++i)
	{
		int index = abs(nums[i]) - 1;
		if (nums[index] < 0)//λ��Ϊ��������ʾ��Ԫ���Ѿ����ֹ��ˣ����ظ�Ԫ��
			result.push_back(index + 1);
		else//λ��Ϊ��������ʾ��Ԫ�ص�һ�γ��֣�������Ϊ����
			nums[index] = -nums[index];
	}
	return result;
}