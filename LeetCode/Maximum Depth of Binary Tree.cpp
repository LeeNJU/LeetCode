#include<algorithm>
#include"TreeNode.h"
//��Ŀ����������һ�ö����������������
//�ⷨ�������ݹ�


int maxDepth(TreeNode* root)
{
	if (root == nullptr)
		return 0;

	return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
}
