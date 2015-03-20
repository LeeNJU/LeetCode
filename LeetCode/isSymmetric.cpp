#include"TreeNode.h"
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