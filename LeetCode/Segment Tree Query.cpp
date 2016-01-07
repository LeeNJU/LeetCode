#include"TreeNode.h"
#include<algorithm>
//��Ŀ����:����һ�������Ӧ���߶�����ÿ���ڵ�洢�˵�ǰ�����ڵ����ֵ������һ�����䣬�ҵ���������ڵ����ֵ
//�ⷨ����:�ݹ�
int query(SegmentTreeNode* root, int start, int end) 
{
	if (end < root->start || start > root->end)//û�н���
		return INT_MIN;
	if (start <= root->start && end >= root->end)//����[start, end]�����˵�ǰ�ڵ������
		return root->max;

	int num1 = query(root->left, start, end);//�����ӽڵ���в�ѯ
	int num2 = query(root->right, start, end);//�����ӽڵ���в�ѯ
	return std::max(num1, num2);//ȡ���ֵ
}

//version 2
//��Ŀ����:����һ�������Ӧ���߶�����ÿ���ڵ�������������ֵ�ڵ�ǰ����ĸ���������һ����ѯ���䣬�����������䷶Χ�ڵĸ���
//�ⷨ����:����ÿ���ڵ����Ǹ������ֱ������ҽڵ��ѯȻ�����

int query2(SegmentTreeNode *root, int start, int end) 
{	
	if (!root || end < root->start || start > root->end)//û�н���
		return 0;
	if (start <= root->start && end >= root->end)//����[start, end]�����˵�ǰ�ڵ������
		return root->count;

	return query(root->left, start, end) + query(root->right, start, end);//�ֱ������ҽڵ��ѯ������������
}