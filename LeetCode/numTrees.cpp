#include"TreeNode.h"
#include<vector>
//题目描述：给定一个数字n，求出总共有多少种唯一的二叉树，每个二叉树存储1到n的值
//解法描述：递推公式 f(i) = Σ 1<=k<=i  f(k - 1) * f(i - k)

int numTrees(int n)
{
	std::vector<int> f(n + 1, 0);
	f[0] = 1;
	f[1] = 1;
	for (int i = 2; i <= n; ++i) {
		for (int k = 1; k <= i; ++k)
			f[i] += f[k - 1] * f[i - k];
	}
	return f[n];
}

//version 2
//题目描述：给定一个n，找到所有符合条件的二叉搜索树
//解法描述:递归，用两个边界

std::vector<TreeNode*> dfs(int left, int right)
{
	std::vector<TreeNode*> result;
	if (left < right)
	{
		result.push_back(nullptr);
		return result;
	}

	for (int i = left; i <= right; ++i)
	{
		std::vector<TreeNode*> left_sub_tree = dfs(left, i - 1);
		std::vector<TreeNode*> right_sub_tree = dfs(i + 1, right);
		for (int j = 0; j < left_sub_tree.size(); ++j)
		{
			for (int k = 0; k < right_sub_tree.size(); ++k)
			{
				TreeNode* root = new TreeNode(i);
				root->left = left_sub_tree[j];
				root->right = right_sub_tree[k];
				result.push_back(root);
			}
		}
	}
	return result;
}

std::vector<TreeNode*> generateTrees(int n) 
{
	return dfs(1, n);
}