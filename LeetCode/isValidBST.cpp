#include<vector>
#include"TreeNode.h"
//��Ŀ����������һ�������ж����Ƿ��Ƕ�����
//�ⷨ�������ݹ鴫������������һ������磬һ�����ҽ磬�ڵ��ֵ��������������м䣬ͬʱ���ж���������������ʱ�������ҽ硣
//bugs  �˷����в�ͨ  ���������
bool isValidBST(TreeNode* root, int lower, int upper)//ע�������long����Ϊ��root��ֵΪINT_MAXʱΪ����
{
	if (root == nullptr)
		return true;
		
	if (root->val <= lower || root->val >= upper)
		return false;

	return root->val > lower && root->val < upper && isValidBST(root->left, lower, root->val) && isValidBST(root->right, root->val, upper);
}

bool isValidBST(TreeNode* root)
{
	return isValidBST(root, INT_MIN, INT_MAX);
}