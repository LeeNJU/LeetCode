#include"TreeNode.h"
#include<vector>
//��Ŀ����:����һ�������һ��query��ÿ��query��������б����ֵС�ĸ���
//�ⷨ����:����һ���߶�����count��ʾ������[start,end]�ĸ�����Ȼ���ÿ��queyr����[0, val - 1]�Ĳ�ѯ
SegmentTreeNode* build(int start, int end)//�����߶�����count��ʾֵ������[start,end]�ڵĸ���
{
	if (start > end)
		return nullptr;

	SegmentTreeNode* root = new SegmentTreeNode(start, end);
	root->count = 0;
	if (start == end)
		return root;

	int mid = (start + end) / 2;
	root->left = build(start, mid);
	root->right = build(mid + 1, end);
	return root;
}

void modify(SegmentTreeNode* root, int val)//�޸��߶�����û����һ��val���Ͱ�countֵ��1
{
	if (val < root->start || val > root->end)
		return;

	if (root->start == root->end)
	{
		++root->count;
		return;
	}

	modify(root->left, val);
	modify(root->right, val);
	root->count = root->left->count + root->right->count;
}

int query(SegmentTreeNode* root, int start, int end)//��ѯ
{
	if (start > root->end || end < root->start)
		return 0;
	if (start <= root->start && root->end <= end)
		return root->count;

	return query(root->left, start, end) + query(root->right, start, end);
}

std::vector<int> countOfSmallerNumber(std::vector<int>& A, std::vector<int> &queries) 
{
	SegmentTreeNode* root = build(0, 10000);//����һ��0��10000���߶�������Ϊֵ������10000
	for (int i = 0; i < A.size(); ++i)//������ÿ��Ԫ�ظ����߶���
		modify(root, A[i]);

	std::vector<int> result;
	for (int i = 0; i < queries.size(); ++i)
		result.push_back(query(root, 0, queries[i] - 1));
	
	return result;
}