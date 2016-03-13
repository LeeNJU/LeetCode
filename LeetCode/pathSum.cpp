#include"TreeNode.h"
#include<vector>
//题目描述：给定一棵二叉树和一个值，找出所有路径，使得路径上的数字之和等于给定的值
//解法描述：递归

void dfs(TreeNode* root, int sum, std::vector<std::vector<int>>& result, std::vector<int> temp)
{
	if (root == nullptr)
		return;

	temp.push_back(root->val);//记录路径上的节点
	if (root->left == nullptr && root->right == nullptr)//叶子节点
	{
		if (root->val == sum)
			result.push_back(temp);
		return;
	}

	dfs(root->left, sum - root->val, result, temp);//左节点递归
	dfs(root->right, sum - root->val, result, temp);//右节点递归
}

std::vector<std::vector<int> > pathSum(TreeNode *root, int sum)
{
	std::vector<std::vector<int>> result;
	std::vector<int> temp;
	dfs(root, sum, result, temp);
	return result;
}

