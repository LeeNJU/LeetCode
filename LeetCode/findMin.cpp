#include <vector>

int findMin(std::vector<int> &num)//将中间的元素与最右边的元素比较，用二分法缩小范围 
{
	int left = 0, right = num.size() - 1, middle = (left + right) / 2;
	while (left < right)
	{
		if (num[middle] > num[right])
		{
			left = middle + 1;
		}
		else
		{
			right = middle;
		}
		middle = (left + right) / 2;
	}
	return num[left];
}