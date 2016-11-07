#include"TreeNode.h"
//题目描述:给定一个二叉树，找到所有的左叶子节点，并求和。例如
//                3
//             9      20
//                 15     7   左叶子节点就是9和15，和为24
//解法描述:递归找到所有叶子节点，由于要判断是不是左叶子节点，所以要传入父节点指针

void dfs(TreeNode* root, TreeNode* parent, int& sum)
{
	if (root == nullptr)
		return;

	if (root->left == nullptr && root->right == nullptr)//找到叶子节点
	{
		if (parent != nullptr && parent->left == root)//左叶子节点
			sum += root->val;
		return;
	}

	dfs(root->left, root, sum);
	dfs(root->right, root, sum);
}

int sumOfLeftLeaves(TreeNode* root) 
{
	int sum = 0;
	dfs(root, nullptr, sum);
	return sum;
}