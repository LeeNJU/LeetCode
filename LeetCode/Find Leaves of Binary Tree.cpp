#include"TreeNode.h"
#include<vector>
//题目描述:给定一个二叉树，找到所有的叶子节点，然后删除叶子节点，得到一个新的二叉树，然后再找到所有叶子节点并
//        删除，直到树为空。例如       1
//                                 2    3
//                               4   5
//        返回结果为[[4,5,3], [2],[1]]
//解法描述:递归找到叶子节点，然后设为nullptr

TreeNode* remove(TreeNode *node, std::vector<int>& leaves) 
{
	if (!node) 
		return nullptr;
	if (!node->left && !node->right) 
	{
		leaves.push_back(node->val);
		return nullptr;
	}
	node->left = remove(node->left, leaves);
	node->right = remove(node->right, leaves);
	return node;
}

std::vector<std::vector<int>> findLeaves(TreeNode* root) 
{
	std::vector<std::vector<int>> result;
	while (root) 
	{
		std::vector<int> leaves;
		root = remove(root, leaves);
		result.push_back(leaves);
	}
	return result;
}