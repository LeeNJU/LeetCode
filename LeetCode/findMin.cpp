#include <vector>

//题目描述：给定一个数组，该数组之前已排好序，但是在某一个点被调换了位置，例如4 5 6 7 0 1 2，找到其中的最小元素，假设数组中不包含重复元素
//解法描述：二分查找

int findMin(std::vector<int>& nums)//将中间的元素与最右边的元素比较，用二分法缩小范围，复杂度为O(lgn)
{
	int left = 0, right = nums.size() - 1;
	while (left < right)
	{
		int middle = (left + right) / 2;
		if (nums[middle] < nums[right])
			right = middle;
		else
			left = middle + 1;
	}
	return nums[left];
}

//版本二：假设数组中包含重复元素
int findMin2(std::vector<int>& nums)
{
	int left = 0, right = nums.size() - 1, middle = 0;
	while (left < right)
	{
		middle = (left + right) / 2;
		if (nums[left] == nums[right])//两遍两个元素相等，只需要移动left或right一个指针就可以了，不能两个都移动,例如[1,2,1]
			++left;
		else if (nums[middle] > nums[right])
			left = middle + 1;
		else
			right = middle;
	}
	return nums[left];
}