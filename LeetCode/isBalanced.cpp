#include<algorithm>
#include"TreeNode.h"
//题目描述：给定一棵二叉树，判断其是否是平衡树，平衡树的定义是左子树和右子树的高度差不能超过1
//解法描述：先写出算出树高度的函数depth，然后递归判断是否平衡



int depth(TreeNode* root)//返回树的高度
{
	if (root == nullptr)
		return 0;

	return std::max(depth(root->left), depth(root->right)) + 1;
}

bool isBalanced(TreeNode* root)
{
	if (root == nullptr)
		return true;
	if (abs(depth(root->left) - depth(root->right)) > 1)//左右子树高度差大于1
		return false;

	return isBalanced(root->left) && isBalanced(root->right);//必须左右子树同时平衡，所以是&&
}