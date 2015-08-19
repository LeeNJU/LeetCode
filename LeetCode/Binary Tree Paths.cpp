#include<vector>
#include<string>
#include"TreeNode.h"
//��Ŀ����������һ����������������и���Ҷ�ӽڵ��·��
//�ⷨ������dfs����
void dfs(std::vector<std::string>& result, std::string t, TreeNode* root)
{
	if (root == nullptr)
		return;

	t = t + std::to_string(root->val) + "->";
	if (root->left == nullptr && root->right == nullptr)//Ҷ�ӽڵ�
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