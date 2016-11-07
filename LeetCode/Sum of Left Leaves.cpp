#include"TreeNode.h"
//��Ŀ����:����һ�����������ҵ����е���Ҷ�ӽڵ㣬����͡�����
//                3
//             9      20
//                 15     7   ��Ҷ�ӽڵ����9��15����Ϊ24
//�ⷨ����:�ݹ��ҵ�����Ҷ�ӽڵ㣬����Ҫ�ж��ǲ�����Ҷ�ӽڵ㣬����Ҫ���븸�ڵ�ָ��

void dfs(TreeNode* root, TreeNode* parent, int& sum)
{
	if (root == nullptr)
		return;

	if (root->left == nullptr && root->right == nullptr)//�ҵ�Ҷ�ӽڵ�
	{
		if (parent != nullptr && parent->left == root)//��Ҷ�ӽڵ�
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