#include"TreeNode.h"
//��Ŀ����:����һ����������ÿһ���Ӹ���Ҷ�ӽڵ��·��������һ����������Щ���ĺͣ�����
//           1
//        2     3   ��Щ��Ϊ12 + 13 = 25
//�ⷨ����:�ݹ�

void dfs(TreeNode* root, int val, int& sum)
{
	if (!root)
		return;

	if (!root->left && !root->right)
	{
		sum = sum + val * 10 + root->val;
		return;
	}

	dfs(root->left, val * 10 + root->val, sum);
	dfs(root->right, val * 10 + root->val, sum);
}

int sumNumbers(TreeNode* root) 
{
	int sum = 0;
	dfs(root, 0, sum);
	return sum;
}