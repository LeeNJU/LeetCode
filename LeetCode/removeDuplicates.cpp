//题目描述：给一个已序数组，删除其中的重复元素，使得每个元素只出现一次，并返回数组长度
//解法：index表示新下标，i=1开始遍历数组，如果A[index]不等于A[i]
int removeDuplicates(int A [], int n)
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