#include"TreeNode.h"
#include<algorithm>
//题目描述:给定一个二叉树，找到其中最长的递增的路径的长度
//解法描述:递归，表示从根节点到当前节点的最大长度

int search(TreeNode *root, TreeNode *parent, int length)
{
	if (!root)
		return length;
	length = (parent && root->val == parent->val + 1) ? length + 1 : 1;
	return std::max(length, std::max(search(root->left, root, length), search(root->right, root, length)));
}

int longestConsecutive(TreeNode* root) 
{
	return search(root, nullptr, 0);
}

