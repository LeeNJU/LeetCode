#include<vector>
#include<numeric>
//题目描述:给定一个未排序数组，重组数组使得满足下面规律:num[0]<=num[1]>=num[2]<=num[3]...
//解法描述:扫描一遍，如果当前元素不满足规律，就与前一个元素交换，交换num[i]和num[i - 1]
void wiggleSort(std::vector<int>& nums) 
{
	int n = nums.size();
	for (int i = 1; i < n; i++)
	{
		if (((i % 2 == 1) && nums[i] < nums[i - 1]) || ((i % 2 == 0) && nums[i] > nums[i - 1]))
			std::swap(nums[i], nums[i - 1]);
	}
}