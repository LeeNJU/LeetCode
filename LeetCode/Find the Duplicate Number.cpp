#include<vector>
//��Ŀ����:����һ�������СΪn + 1,ֻ����1��n����ô���б����ظ�Ԫ�أ��ҵ�����ظ�Ԫ��(�����޸�����)
//�ⷨ����:���ַ�������������С�ڵ���middle�ĸ������������С��middle����ô�ظ�Ԫ��һ����middle��right֮�䣬��֮����left
//        ��middle֮�䣬ע�������middle��left��right������Ҫ�ҵ�Ԫ��
int count_number(std::vector<int>& num, int value)
{
	int count = 0;
	for (int i = 0; i < num.size(); ++i)
	{
		if (num[i] <= value)
			++count;
	}
	return count;
}

int findDuplicate(std::vector<int>& nums)
{
	int left = 1, right = nums.size() - 1, middle = 0;
	while (left <= right)
	{
		middle = (left + right) / 2;
		int count = count_number(nums, middle);
		if (count <= middle)
			left = middle + 1;
		else
			right = middle - 1;
	}
	return left;
}