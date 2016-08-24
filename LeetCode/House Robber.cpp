#include<vector>
#include<algorithm>
#include"TreeNode.h"
//��Ŀ����������һ�������������ÿ����ͥ��Ǯ������ȥ���٣����ǲ����������������ң�����������ٶ���Ǯ
//�ⷨ��������̬�滮  dp[i] = max(dp[i - 1], dp[i - 2] + n[i])

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

//����2�����跿�ӵ���������β�����ģ�����һ�����Ӻ����һ�����������ڵģ�����ͬʱ����
//�ⷨ����:���ڵ�һ�Һ����һ�Ҳ���ͬʱ�����Ǿͷֱ�ѵ�һ�Һ����һ��ȥ�����ֱ�����ܹ��������ֵ��Ȼ�����
//        ȡ���
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


//����3:
//���ӱ���֯�ɶ���������ʽ�����ӽڵ㲻��ͬʱ�������������������ֵ
//�ⷨ����:�ݹ飬��һ��pair��ʾֵ��pair.first��ʾ��������ǰ�ڵ�����ֵ��pair.second��ʾ������ǰ�ڵ�����ֵ
//        
std::pair<int, int> dfs(TreeNode* root)
{
	std::pair<int, int> dp = std::make_pair<int, int>(0, 0);
	if (!root)
		return dp;

	std::pair<int,int> left = dfs(root->left);
	std::pair<int, int> right = dfs(root->right);
	dp.first = std::max(left.first, left.second) + std::max(right.first, right.second);
	dp.second = left.first + right.first + root->val;
	
	return dp;
}

int rob(TreeNode* root) 
{
	std::pair<int, int> result = dfs(root);
	return std::max(result[0], result[1]);
}
