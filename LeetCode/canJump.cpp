bool canJump(int A[], int n) //记录每一步能够前进的最大maxIndex，判断maxIndex是否包含最后一个元素
{
	if (n == 1)
		return true;

	int maxIndex = 0;
	for (int i = 0; i < n - 1; ++i)
	{
		if ((A[i] + i) >= maxIndex)
		{
			maxIndex = i + A[i];
		}

		if (maxIndex >= n - 1)
			return true;
		if ((i + 1) > maxIndex)//循环迭代是要判断能够前进到下一个index，因为maxIndex如果小于i + 1的话，说明无法达到下一个index
			return false;
	}
	return false;
}