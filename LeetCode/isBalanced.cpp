#include<algorithm>
#include"TreeNode.h"
//��Ŀ����������һ�ö��������ж����Ƿ���ƽ������ƽ�����Ķ��������������������ĸ߶Ȳ�ܳ���1
//�ⷨ��������д��������߶ȵĺ���depth��Ȼ��ݹ��ж��Ƿ�ƽ��



int depth(TreeNode* root)//�������ĸ߶�
{
	if (root == nullptr)
		return 0;

	return std::max(depth(root->left), depth(root->right)) + 1;
}

bool isBalanced(TreeNode* root)
{
	if (root == nullptr)
		return true;
	if (abs(depth(root->left) - depth(root->right)) > 1)//���������߶Ȳ����1
		return false;

	return isBalanced(root->left) && isBalanced(root->right);//������������ͬʱƽ�⣬������&&
}