#include<vector>

//��Ŀ����:����һ��δ��������飬�ҵ����е�k���Ԫ��
//�ⷨ����:�����е�k���Ԫ�ص��±�Ϊn - k�����ÿ��������partition������firstָ�����鿪ͷ��lastָ���β��
//        ��first��last����Ľ���partition�������᷵��һ���±�index�����index����n - k����ôA[n - k]Ԫ��
//        ���ǽ�������indexС��n - k��firstָ��index����һ��Ԫ�أ��������n - k��lastָ��index����һ��Ԫ��

int partition(std::vector<int>& nums, int first, int last)
{
	int pivot = nums[last];
	int i = first - 1;
	for (int j = first; j < last; ++j)
	{
		if (nums[j] <= pivot)
			std::swap(nums[++i], nums[j]);
	}
	std::swap(nums[++i], nums[last]);
	return i;
}

int findKthLargest(std::vector<int>& nums, int k)
{
	int first = 0, last = nums.size() - 1;
	int n = nums.size();
	while (first < last)
	{
		int index = partition(nums, first, last);
		if (index == n - k)
			return nums[n - k];
		else if (index < n - k)
			first = index + 1;
		else
			last = index - 1;
	}
	return nums[first];
}