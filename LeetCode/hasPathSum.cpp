#include"TreeNode.h"
//题目描述：给定一棵二叉树和一个值，判断这课树是否有一条路径，使得这条路径上的数字之和等于给定的值
//解法描述：递归


bool hasPathSum(TreeNode* root, int sum)
{
	if (root == nullptr)
		return false;

	if (root->left == nullptr && root->right == nullptr)
		return sum == root->val;
	
	return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}