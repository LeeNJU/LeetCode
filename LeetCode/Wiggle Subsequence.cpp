#include<vector>
#include<algorithm>
//题目描述:给定一个整数数组，返回最长的wiggle sequence的长度，wiggle sequence要严格的上下起伏，例如
//        [1,7,4,9,2,5]，就是一个wiggle sequence，而[1,4,7,2,5]则不是。数组中可能存在多个一样长的wiggle
//        sequence,返回其中任意一个最长的。
//解法描述:贪心算法，用p当前元素是递增的长度，q表示当前元素是递减的长度，如果当前元素比前一个元素大，那么p等于
//        q + 1, 如果当前元素比前一个元素小，那么q等于p + 1

int wiggleMaxLength(std::vector<int>& nums) 
{
	if (nums.empty())
		return 0;

	int p = 1, q = 1, result = 1;
	for (int i = 1; i < nums.size(); ++i) 
	{
		if (nums[i] > nums[i - 1]) 
			p = q + 1;
		else if (nums[i] < nums[i - 1]) 
			q = p + 1;

		result = std::max(std::max(p, q), result);
	}
	return result;
}