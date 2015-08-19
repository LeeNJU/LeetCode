#include<vector>
#include<string>
#include"TreeNode.h"
//题目描述：给定一个二叉树，输出所有根到叶子节点的路径
//解法描述：dfs深搜
void dfs(std::vector<std::string>& result, std::string t, TreeNode* root)
{
	if (root == nullptr)
		return;

	t = t + std::to_string(root->val) + "->";
	if (root->left == nullptr && root->right == nullptr)//叶子节点
		result.push_back(t.substr(0, t.size() - 2));

	dfs(result, t, root->left);
	dfs(result, t, root->right);
}

std::vector<std::string> binaryTreePaths(TreeNode* root) 
{
	std::vector<std::string> result;
	dfs(result, "", root);
	return result;
}