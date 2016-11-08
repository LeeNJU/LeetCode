#include<vector>
#include<numeric>
#include<algorithm>

//��Ŀ����:����һ��δ�������飬��������ʹ�������������:num[0]<=num[1]>=num[2]<=num[3]...
//�ⷨ����:ɨ��һ�飬�����ǰԪ�ز�������ɣ�����ǰһ��Ԫ�ؽ���������num[i]��num[i - 1]
void wiggleSort(std::vector<int>& nums) 
{
	int n = nums.size();
	for (int i = 1; i < n; ++i)
	{
		if (((i % 2 == 1) && nums[i] < nums[i - 1]) || ((i % 2 == 0) && nums[i] > nums[i - 1]))
			std::swap(nums[i], nums[i - 1]);
	}
}

//�汾2:����һ��δ�������飬��������ʹ��nums[0] < nums[1] > nums[2] < nums[3]...
//�ⷨ����:
void wiggleSort2(std::vector<int>& nums) 
{
	int n = nums.size();
	auto midptr = nums.begin() + n / 2;
	std::nth_element(nums.begin(), midptr, nums.end());
	int mid = *midptr;

#define A(i) nums[(1+2*(i)) % (n|1)]

	int i = 0, j = 0, k = n - 1;
	while (j <= k) 
	{
		if (A(j) > mid)
			std::swap(A(i++), A(j++));
		else if (A(j) < mid)
			std::swap(A(j), A(k--));
		else
			++j;
	}
}