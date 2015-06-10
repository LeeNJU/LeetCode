#include<vector>

//题目描述：给定一个未排序的数组，找到其中第k大的元素
//解法描述：数组中第k大的元素的下标为n - k，利用快排里面的partition操作，first指向数组开头，last指向结尾，对first到last区间的进行partition操作，
//会返回一个下标index，如果index等于n - k，那么A[n - k]元素就是结果，如果index小于n - k，first指向index的下一个元素，如果大于n - k，last指向
//index的上一个元素

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