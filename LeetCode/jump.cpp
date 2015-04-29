#include<algorithm>
#include<vector>
//题目描述：给定一个非负数组，每个元素表示能够向前跳跃的最大步数，求出跳到最后一个元素的最小步数
//解法描述：贪心  当curRch < i，说明ret次jump已经不足以覆盖当前第i个元素，因此需要增加一次jump，使之达到curMax

int jump(std::vector<int>& nums)
{
	int result = 0;//最小步数
	int curMax = 0;//当前能够到达的最大范围
	int curRch = 0;//从num[0]跳跃result次后能够达到的最大范围
	for (int i = 0; i < nums.size(); i++)
	{
		if (curRch < i)
		{
			result++;
			curRch = curMax;
		}
		curMax = std::max(curMax, nums[i] + i);
	}
	return result;
}