//��Ŀ����������һ�����飬�����е�Ԫ������k��������{1,2,3,4,5,6,7}����3����{5,6��7,1,2,3,4}
//�ⷨ��������3�η�ת��[0,n-k-1]��תһ��,[n-k,n-1]��תһ�Σ�[0,n-1]��תһ��

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
	k %= n;//����Ҫע�⣬��Ϊk����Զ����n
	r(nums, 0, n - k - 1);
	r(nums, n - k, n - 1);
	r(nums, 0, n - 1);
}