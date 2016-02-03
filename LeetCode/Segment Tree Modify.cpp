#include"TreeNode.h"
#include<algorithm>
//��Ŀ����:����һ�������Ӧ���߶��������ڶ�����ĳ��index��ֵ�����޸ģ����޸ĺ���߶���
//�ⷨ����:�ݹ飬�ڵ�ǰ�����жϣ�Ҫ�޸ĵ�index�������ӽڵ㻹�����ӽڵ�
void modify(SegmentTreeNode* root, int index, int value) 
{
	if (!root || index > root->end || index < root->start)//û�н���
		return;

	if (root->start == root->end)//Ҫ�޸ĵĽڵ�
	{
		root->max = value;
		return;
	}

	modify(root->left, index, value);
	modify(root->right, index, value);
	root->max = std::max(root->left->max, root->right->max);
}