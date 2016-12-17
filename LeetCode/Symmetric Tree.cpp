#include"TreeNode.h"
#include<queue>
//��Ŀ����������һ�����������ж����Ƿ��Ǿ���ԳƵ�
//�ⷨ������Ҫ�ж��Ƿ���Գƣ���������������ֱ��жϣ�������дһ������������Ϊ����������������Ȼ��ݹ��ж�

bool symmetric(TreeNode* left, TreeNode* right)
{
	if (left == nullptr && right == nullptr)
		return true;

	if (left == nullptr || right == nullptr)
		return false;
	else if (left->val != right->val)
		return false;
	else
		return symmetric(left->left, right->right) && symmetric(left->right, right->left);
}

bool isSymmetric(TreeNode* root)
{
	if (root == nullptr)
		return true;

	return symmetric(root->left, root->right);
}

/*
������queue���в�α�����
bool isSymmetric(TreeNode* root)
{
	TreeNode *left, *right;
	if (!root)
		return true;

	std::queue<TreeNode*> q1, q2;
	q1.push(root->left);
	q2.push(root->right);
	while (!q1.empty() && !q2.empty())
	{
		left = q1.front();
		q1.pop();
		right = q2.front();
		q2.pop();
		if (left == nullptr && right == nullptr)
			continue;
		if (left == nullptr || right == nullptr)
			return false;
		if (left->val != right->val)
			return false;
		q1.push(left->left);
		q1.push(left->right);
		q2.push(right->right);
		q2.push(right->left);
	}
	return true;
}*/