#include<vector>
//给定一个已序数组，但是该数组在某一个位置被反转了，在该数组中查找指定的元素，例如array={4,5,6,1,2,3}查找2
//解法：二分法,注意边界！！尤其是target与A[middle]和A[first]的比较！！

int search(int A[], int n, int target)
{
	int first = 0, last = n - 1, middle = 0;
	while (first <= last)
	{
		middle = (first + last) / 2;
		if (A[middle] == target)
			return middle;
		if (A[middle] >= A[first])//middle先与first比较
		{
			if (A[middle] > target && target >= A[first])//确定target是再middle左边还是右边
				last = middle - 1;
			else
				first = middle + 1;
		}
		else
		{
			if (A[middle] < target && target <= A[last])//确定target是在middle左边还是右边
				first = middle + 1;
			else
				last = middle - 1;
		}
	}
	return -1;
}

//版本二：如果有重复元素呢
bool search2(std::vector<int>& nums, int target) 
{
	int left = 0, right = nums.size() - 1, middle  = 0;
	while (left <= right)
	{
		middle = (left + right) / 2;
		if (nums[middle] == target)
			return true;
		else if (nums[left] == nums[right]) //对于这种已序数组在某个位置被旋转的题，先比较left和right是否相等
			++left;
		else if (nums[middle] >= nums[left])
		{
			if (target >= nums[left] && nums[middle] > target)
				right = middle - 1;
			else
				left = middle + 1;
		}
		else
		{
			if (target <= nums[right] && target > nums[middle])
				left = middle + 1;
			else
				right = middle - 1;
		}
	}
	return false;
}