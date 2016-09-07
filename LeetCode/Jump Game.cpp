#include<vector>
#include<algorithm>
//题目描述：给定一个数组，每个元素表示能够向前跳跃的最大步数，求出能否跳跃到最后一个元素
//解法描述：贪心，记录当前元素能够跳跃的最远距离，判断最远距离是否大于数组长度

bool canJump(std::vector<int>& nums) //记录每一步能够前进的最大maxIndex，判断maxIndex是否包含最后一个元素
{
	if (nums.empty())
		return false;

	if (nums[0] == 0 && nums.size() == 1)
		return true;

	int max_index = 0;
	for (int i = 0; i < nums.size() && i <= max_index; ++i)
	{
		max_index = std::max(max_index, i + nums[i]);
		if (max_index >= nums.size() - 1)
			return true;
	}
	return false;
}