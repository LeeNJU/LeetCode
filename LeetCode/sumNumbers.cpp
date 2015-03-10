#include"TreeNode.h"
//题目描述：给定一棵二叉树，根节点到每一个叶子节点为一条路径，代表一个数，求出这些数的和
//解法描述：递归

int sumNumbers(TreeNode *root)
{
	return dfs(root, 0);
}

int dfs(TreeNode* root, int sum)
{
	if (root == nullptr)
		return 0;

	if (root->left == nullptr && root->right == nullptr)
		return sum * 10 + root->val;

	return dfs(root->left, sum * 10 + root->val) + dfs(root->right, sum * 10 + root->val);
}