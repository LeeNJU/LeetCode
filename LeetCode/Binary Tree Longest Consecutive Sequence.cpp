#include"TreeNode.h"
#include<algorithm>
//��Ŀ����:����һ�����������ҵ�������ĵ�����·���ĳ���
//�ⷨ����:�ݹ飬��ʾ�Ӹ��ڵ㵽��ǰ�ڵ����󳤶�

int search(TreeNode *root, TreeNode *parent, int length)
{
	if (!root)
		return length;
	length = (parent && root->val == parent->val + 1) ? length + 1 : 1;
	return std::max(length, std::max(search(root->left, root, length), search(root->right, root, length)));
}

int longestConsecutive(TreeNode* root) 
{
	return search(root, nullptr, 0);
}

