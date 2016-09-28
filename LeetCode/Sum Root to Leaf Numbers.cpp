#include"TreeNode.h"
//题目描述:给定一个二叉树，每一条从根到叶子节点的路径都代表一个数，求这些数的和，例如
//           1
//        2     3   这些数为12 + 13 = 25
//解法描述:递归

void dfs(TreeNode* root, int val, int& sum)
{
	if (!root)
		return;

	if (!root->left && !root->right)
	{
		sum = sum + val * 10 + root->val;
		return;
	}

	dfs(root->left, val * 10 + root->val, sum);
	dfs(root->right, val * 10 + root->val, sum);
}

int sumNumbers(TreeNode* root) 
{
	int sum = 0;
	dfs(root, 0, sum);
	return sum;
}