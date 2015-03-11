//题目描述：给定一个数组，将其中的元素右移k步，例如{1,2,3,4,5,6,7}右移3步后，{5,6，7,1,2,3,4}
//解法描述：做3次反转，[0,n-k-1]反转一次,[n-k,n-1]反转一次，[0,n-1]反转一次

void r(int nums[], int first, int last)
{
	for (; first <= last; ++first, --last)
	{
		int temp = nums[last];
		nums[last] = nums[first];
		nums[first] = temp;
	}
}
void rotate(int nums[], int n, int k)
{
	k %= n;//这里要注意，因为k可能远大于n
	r(nums, 0, n - k - 1);
	r(nums, n - k, n - 1);
	r(nums, 0, n - 1);
}