#include<vector>
//给定一个已序数组和一个值，从中找出这个值在数组的范围，用下标表示，如果该值不存在，则返回2个-1
//解法：二分法，用lower_bound和upper_bound
std::vector<int> searchRange(int A [], int n, int target)
{
	std::vector<int> result;
	int left = 0, right = n - 1, middle = 0;
	int first = 0, last = n - 1;
	while (left <= right)//lower_bound源码，寻找最左边的边界
	{
		middle = (left + right) / 2;
		if (A[middle] < target)
			left = middle + 1;
		else
			right = middle - 1;
	}
	first = left;
	if (first >= n || A[first] != target)//判断元素是否存在于数组中
	{
		result.push_back(-1);
		result.push_back(-1);
		return result;
	}

	left = 0, right = n - 1, middle = 0;
	while (left <= right)//upper_bound源码，寻找最右边的边界
	{
		middle = (left + right) / 2;
		if (A[middle] <= target)//此处是唯一不同的地方
			left = middle + 1;
		else
			right = middle - 1;

	}
	last = left;

	result.push_back(first);
	result.push_back(last - 1);//upper_bound返回的是元素的下一个位置，所以要减去1
	return result;
}