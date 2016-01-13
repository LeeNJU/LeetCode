#include"TreeNode.h"
//题目描述:给定一个二叉树，求出uni-value subtree的子树，uni-value subtree指该子树所有的节点的值都一样，例如
//              5          应该返回4
//            1    5
//          5   5    5
//解法描述:递归，关键是判断子树是不是uni-value subtres
int countUnivalSubtrees(TreeNode* root) 
{
	int count = 0;
	countUnivalSubtreesRecursive(root, count);
	return count;
}

bool countUnivalSubtreesRecursive(TreeNode* root, int& count)
{
	if (root == nullptr) 
		return true;

	bool isLeftUnival = countUnivalSubtreesRecursive(root->left, count);
	bool isRightUnival = countUnivalSubtreesRecursive(root->right, count);

	if (isLeftUnival && isRightUnival && ((root->left == nullptr) || root->left->val == root->val)
		&& ((root->right == nullptr) || root->right->val == root->val)
		) //左右子树都是unival子树，并且根的值与左右子节点相同，这里包含了左右子节点为空的情况
	{
		++count;
		return true;
	}
	return false;
}