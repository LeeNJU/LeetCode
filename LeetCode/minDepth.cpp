#include<iostream>
#include<algorithm>
#include"TreeNode.h"
//题目描述：给定一棵二叉树，求出它的最小深度
//解法描述：递归


int minDepth(TreeNode* root)
{
	if (root == nullptr)
		return 0;

	if (root->left == nullptr)
		return minDepth(root->right) + 1;
	else if (root->right == nullptr)
		return minDepth(root->left) + 1;
	else
		return std::min(minDepth(root->left), minDepth(root->right)) + 1;
}