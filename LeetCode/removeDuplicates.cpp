//题目描述：给一个已序数组，删除其中的重复元素，使得每个元素只出现一次，并返回数组长度
//解法：index表示新下标，i=1开始遍历数组，如果A[index]不等于A[i]
int removeDuplicate(int A [], int n)
{
	if (n == 0)
		return 0;

	int index = 0;
	for (int i = 1; i < n; ++i)//从i=1开始遍历
	{
		if (A[index] != A[i])
		{
			A[++index] = A[i];//注意是++index
		}
	}
	return index + 1;
}

//版本二：给定一个已序数组，删除其中的重复元素，使得每个元素最多出现两次，并返回长度
//解法：与上题类似，加一个变量记录次数
int removeDuplicates(int A [], int n)
{
	if (n == 0)
		return 0;

	int occur = 1, index = 0;
	for (int i = 1; i < n; ++i)//从i=1开始
	{
		if (A[index] == A[i])//判断是否相等
		{
			if (occur < 2)//判断出现的次数
			{
				A[++index] = A[i];
				++occur;
			}
		}
		else
		{
			A[++index] = A[i];
			occur = 1;
		}
	}
	return index + 1;
}