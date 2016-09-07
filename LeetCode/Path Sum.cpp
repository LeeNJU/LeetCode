#include"TreeNode.h"
//��Ŀ����:����һ�ö�������һ��ֵ���ж�������Ƿ���һ��·����ʹ������·���ϵ�����֮�͵��ڸ�����ֵ
//�ⷨ����:�ݹ�


bool hasPathSum(TreeNode* root, int sum)
{
	if (root == nullptr)
		return false;

	if (root->left == nullptr && root->right == nullptr)
		return sum == root->val;
	
	return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}

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