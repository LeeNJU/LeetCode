#include<vector>
#include<string>
//��Ŀ����:����һ�����������һ��lower��upper��Χ���ҵ���������ʧ�����䣬����[0, 1, 3, 50, 75]��lower = 0��
//        upper = 99����ô��ʧ��������["2", "4->49", "51->74", "76->99"]
//�ⷨ����:i��ʾ��ǰӦ�ó��ֵ����֣�Ȼ���������
std::vector<std::string> findMissingRanges(std::vector<int>& nums, int lower, int upper)
{
	std::vector<std::string> result;
	int i = lower;
	for (int j = 0; j < nums.size(); ++j)
	{
		if (nums[j] != i)//�ҵ�����������֣�˵���ҵ���һ������
		{
			if (i == nums[j] - 1)//����ֻ��һ��Ԫ��
				result.push_back(std::to_string(i));
			else
				result.push_back(std::to_string(i) + "->" + std::to_string(nums[j] - 1));
			i = nums[j] + 1;
		}
		else
			++i;
	}

	if (i < upper)//���Ҫ����upper
	{
		if (i == upper)
			result.push_back(std::to_string(i));
		else
			result.push_back(std::to_string(i) + "->" + std::to_string(upper));
	}
	return result;
}