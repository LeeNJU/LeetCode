#include<vector>
#include<algorithm>
#include"TreeNode.h"
//题目描述：给定一个整数数组代表每个家庭的钱，现在去抢劫，但是不能抢劫相连的两家，求最大能抢劫多少钱
//解法描述：动态规划  dp[i] = max(dp[i - 1], dp[i - 2] + n[i])

int rob(std::vector<int>& nums)
{
	if (nums.size() <= 1) 
		return nums.empty() ? 0 : nums[0];
	
	std::vector<int> dp = { nums[0], std::max(nums[0], nums[1]) };
	for (int i = 2; i < nums.size(); ++i) 
	{
		dp.push_back(std::max(nums[i] + dp[i - 2], dp[i - 1]));
	}
	return dp.back();
}

//变种2：假设房子的排列是首尾相连的，即第一个房子和最后一个房子是相邻的，不能同时抢劫
//解法描述：由于第一家和最后一家不能同时抢，那就分别把第一家和最后一家去掉，分别算出能够抢的最大值，然后二者去最大
int rob(std::vector<int> &nums, int left, int right)
{
	if (right - left <= 1) 
		return nums[left];
	
	std::vector<int> dp(right, 0);
	dp[left] = nums[left];
	dp[left + 1] = std::max(nums[left], nums[left + 1]);
	for (int i = left + 2; i < right; ++i) 
	{
		dp[i] = std::max(nums[i] + dp[i - 2], dp[i - 1]);
	}
	return dp.back();
}
int rob2(std::vector<int>& nums) 
{
	if (nums.size() <= 1) 
		return nums.empty() ? 0 : nums[0];
	return std::max(rob(nums, 0, nums.size() - 1), rob(nums, 1, nums.size()));
}


//变种3:
//房子被组织成二叉树的形式，父子节点不能同时被抢，求能抢到的最大值

int dfs(TreeNode* root, bool rob)
{
	if (root == nullptr)
		return 0;

	if (rob)
	{
		int sum = std::max(dfs(root->left, true), dfs(root->right, true));
		return std::max(sum, root->val + std::max(dfs(root->left, false), dfs(root->right, false)));
	}
	else
	{
		return std::max(dfs(root->left, false), dfs(root->right, false));
	}
}

int rob(TreeNode* root) 
{
	return dfs(root, true);
}