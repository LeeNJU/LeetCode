#include<vector>
//��Ŀ����:����һ�����飬���鳤����n��ÿ��Ԫ�ض�������[1,n]֮�䣬�е�Ԫ�س������Σ��е�Ԫ�س���һ�Σ���1��n
//        ֮�䣬�ҵ���ЩԪ��û�г�������������У�����[4,3,2,7,8,2,3,1]������[5,6]����Ϊ5��6û�г���
//�ⷨ����:ɨ�����飬�Ѷ�Ӧ�±��Ԫ����Ϊ���������統ǰԪ����4�����±�Ϊ3��Ԫ����Ϊ���ĸ������������ֹ���Ԫ��
//        ��Ӧ���±��ֵ���Ǹ�����Ȼ��ɨ�����飬���ĳ��ֵ��������˵������±겻������������С�
//        Ҳ������first missing number�Ľⷨ

std::vector<int> findDisappearedNumbers(std::vector<int>& nums)
{
	for (int val : nums)
	{
		int index = abs(val) - 1;
		if (nums[index] > 0)//������Ԫ���Ѿ��Ǹ���������������Ϊ�е�Ԫ�س���2��
			nums[index] = -nums[index];
	}

	std::vector<int> result;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] > 0)//�ҵ����������±�
			result.push_back(i + 1);
	}
	return result;
}