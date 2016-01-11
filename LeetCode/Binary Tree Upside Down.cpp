#include"TreeNode.h"
//题目描述:给定一个二叉树，每个节点要么没有右子节点，要么有左子节点和右子节点，并且右子节点是叶子节点,现在对
//        该二叉树进行反转，使得原来的右子节点变成左叶子节点，例如:
//            1                 4
//          2    3  ——>       5    2
//        4   5                  3    1
//解法描述:对于每个节点，兄弟节点变成左子节点，父节点变成右子节点，可以用递归
TreeNode *upsideDownBinaryTree(TreeNode *root)
{
	TreeNode* parent = nullptr;//保存上一步的父亲节点和兄弟节点
	TreeNode* right = nullptr;
	while (root)
	{
		TreeNode* left = root->left;
		root->left = right;
		right = root->right;
		root->right = parent;
		parent = root;
		root = left;
	}
	return parent;
}