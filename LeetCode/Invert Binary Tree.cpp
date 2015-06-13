#include"TreeNode.h"
//题目描述：给定一棵二叉树，将其左右交换
//解法描述：递归交换左右子树

TreeNode* invertTree(TreeNode* root)
{
	if (root == nullptr)
		return root;

	TreeNode* temp = root->left;
	root->left = root->right;
	root->right = temp;

	invertTree(root->left);
	invertTree(root->right);
	return root;
}