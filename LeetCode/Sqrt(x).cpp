//题目描述：给定一个值x，求出它的平方根
//解法描述：二分查找

int sqrt(int x) 
{
	if (x == 0)
		return 0;
	if (x == 1)
		return 1;

	int left = 1, right = x;
	while (left <= right)//循环结束，left指向正确解的下一个元素
	{
		int middle = (left + right) / 2;
		if (middle == x / middle)
			return middle;
		else if (middle < x / middle)
			left = middle + 1;
		else
			right = middle - 1;
	}

	return left - 1;
}