#include<vector>
//题目描述:nums，求出一个数组output，使得output[i]等于数组所有除了nums[i]之外的元素的乘积，不能用除法
//解法描述:用两个数组，数组left[i]表示nums[0]到nums[i - 1]的乘积，数组right[i]表示数组nums[i + 1]到
//         nums[nums.size() - 1]的乘积，最后把两个数组依次相乘
std::vector<int> productExceptSelf(std::vector<int>& nums) 
{
	std::vector<int> result(nums.size(), 0);
	std::vector<int> left(nums.size(), 1);
	std::vector<int> right(nums.size(), 1);
	for (int i = 1; i < nums.size(); ++i)
		left[i] = left[i - 1] * nums[i - 1];
	for (int i = nums.size() - 2; i >= 0; --i)
		right[i] = right[i + 1] * nums[i + 1];
	for (int i = 0; i < nums.size(); ++i)
		result[i] = left[i] * right[i];
	return result;
}