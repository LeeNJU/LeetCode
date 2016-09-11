#include"TreeNode.h"
//��Ŀ����:����һ�������������uni-value subtree��������uni-value subtreeָ���������еĽڵ��ֵ��һ��������
//              5          Ӧ�÷���4
//            1    5
//          5   5    5
//�ⷨ����:�ݹ飬�ؼ����ж������ǲ���uni-value subtres

bool countUnivalSubtreesRecursive(TreeNode* root, int& count)
{
	if (root == nullptr)
		return true;

	bool isLeftUnival = countUnivalSubtreesRecursive(root->left, count);
	bool isRightUnival = countUnivalSubtreesRecursive(root->right, count);

	if (isLeftUnival && isRightUnival && ((root->left == nullptr) || root->left->val == root->val)
		&& ((root->right == nullptr) || root->right->val == root->val)
		) //������������unival���������Ҹ���ֵ�������ӽڵ���ͬ����������������ӽڵ�Ϊ�յ����
	{
		++count;
		return true;
	}
	return false;
}

int countUnivalSubtrees(TreeNode* root) 
{
	int count = 0;
	countUnivalSubtreesRecursive(root, count);
	return count;
}