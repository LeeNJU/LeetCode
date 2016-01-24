#include<vector>
#include<algorithm>
//题目描述：给定一个正整数数组和一个正整数s，从数组中找到和大于等于s的最小子数组的长度,例如[2,3,1,2,4,3]和
//         s = 7，最小长度为[4,3]
//解法描述：用left和right两个指针维护这个子数组，sum为子数组的和，向右移动right，直到sum大于等于s，然后循环去除子数组的左边部分

int minSubArrayLen(int s, std::vector<int>& nums)
{
	int min_length = nums.size() + 1, sum = 0;//把min_length设成一个比较大的值，方便下面比较
	int left = 0, right = 0;
	while (right < nums.size())
	{
		sum += nums[right];
		if (sum >= s)//sum一旦大于s，表明至少存在一个解
		{
			while (sum - nums[left] >= s)//去除左边多余的元素，left向右移动
			{
				sum -= nums[left];
				++left;
			}
			min_length = std::min(min_length, right - left + 1);
		}
		++right;
	}
	return min_length == nums.size() + 1 ? 0 : min_length;//如果min_length为初始值，说明无解，返回0
}