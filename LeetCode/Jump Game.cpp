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

//题目描述:给定一个非负数组，每个元素表示能够向前跳跃的最大步数，求出跳到最后一个元素的最小步数
//解法描述:贪心,当last < i，说明count次jump已经不足以覆盖当前第i个元素，因此需要增加一次jump，使之达到
//        cur

int jump(std::vector<int>& nums)
{
	int count = 0;//最小步数
	int last = 0;//上一次算出的覆盖范围
	int cur = 0;//目前能够到达的最长范围
	for (int i = 0; i < nums.size(); ++i)
	{
		if (last < i)
		{
			++count;
			last = cur;
		}
		cur = std::max(cur, nums[i] + i);
	}
	return count;
}