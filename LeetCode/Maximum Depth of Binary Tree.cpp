#include<algorithm>
#include"TreeNode.h"
//题目描述：给定一棵二叉树，求出最大深度
//解法描述：递归


int maxDepth(TreeNode* root)
{
	if (root == nullptr)
		return 0;

	return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
}
