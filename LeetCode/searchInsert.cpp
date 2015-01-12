//给定一个数组和一个target，从数组中找到target并返回其下标，如果数组中不存在target，则返回可以插入改元素的位置的下标
//解法：二分法查找结束后，如果找到该元素则成功返回，如果没有找到该元素，first指向该插入的位置

int searchInsert(int A[], int n, int target)
{
	int first = 0, last = n - 1, middle = 0;
	while (first <= last)
	{
		middle = (first + last) / 2;
		if (A[middle] == target)
			return middle;
		else if (A[middle] < target)
			first = middle + 1;
		else
			last = middle - 1;
	}
	return first;
}
