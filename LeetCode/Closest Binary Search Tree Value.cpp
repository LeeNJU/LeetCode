#include"TreeNode.h"
//题目描述:给定一个二叉搜索树和一个target值，在树中找到与target最接近的值
//解法描述:二叉树遍历
int closestValue(TreeNode* root, double target) 
{
	int closest = root->val;
	while (root) 
	{
		if (abs(closest - target) >= abs(root->val - target))
			closest = root->val;
		root = target < root->val ? root->left : root->right;
	}
	return closest;
}