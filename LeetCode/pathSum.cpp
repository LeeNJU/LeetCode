#include"TreeNode.h"
#include<vector>
//��Ŀ����������һ�ö�������һ��ֵ���ҳ�����·����ʹ��·���ϵ�����֮�͵��ڸ�����ֵ
//�ⷨ�������ݹ�

void dfs(TreeNode* root, int sum, std::vector<std::vector<int>>& result, std::vector<int> temp)
{
	if (root == nullptr)
		return;

	temp.push_back(root->val);//��¼·���ϵĽڵ�
	if (root->left == nullptr && root->right == nullptr)//Ҷ�ӽڵ�
	{
		if (root->val == sum)
			result.push_back(temp);
		return;
	}

	dfs(root->left, sum - root->val, result, temp);//��ڵ�ݹ�
	dfs(root->right, sum - root->val, result, temp);//�ҽڵ�ݹ�
}

std::vector<std::vector<int> > pathSum(TreeNode *root, int sum)
{
	std::vector<std::vector<int>> result;
	std::vector<int> temp;
	dfs(root, sum, result, temp);
	return result;
}

