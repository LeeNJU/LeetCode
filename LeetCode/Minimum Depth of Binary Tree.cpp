#include<iostream>
#include<algorithm>
#include"TreeNode.h"
//��Ŀ����������һ�ö����������������С���
//�ⷨ�������ݹ�


int minDepth(TreeNode* root)
{
	if (root == nullptr)
		return 0;

	if (root->left == nullptr)
		return minDepth(root->right) + 1;
	else if (root->right == nullptr)
		return minDepth(root->left) + 1;
	else
		return std::min(minDepth(root->left), minDepth(root->right)) + 1;
}