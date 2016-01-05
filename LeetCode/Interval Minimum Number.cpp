#include"TreeNode.h"
#include<vector>
#include<algorithm>
//��Ŀ����:����һ�������һЩquery�������Щquery֮�����Сֵ������[1,2,7,8,5], and queries [(1,2),(0,4),(2,4)], 
//        Ӧ�÷���[2,1,5]
//�ⷨ����:�߶���
SegmentTreeNode* build(std::vector<int>& A, int start, int end)//�����߶���
{
	if (end < start)
		return nullptr;

	SegmentTreeNode* root = new SegmentTreeNode(start, end);
	if (start == end)
	{
		root->max = A[start];
		return root;
	}

	int mid = (start + end) / 2;
	root->left = build(A, start, mid);
	root->right = build(A, mid + 1, end);
	root->max = std::min(root->left->max, root->right->max);
	return root;
}

int query(SegmentTreeNode* root, int start, int end)//��ѯĳ��query
{
	if (!root || end < root->start || start > root->end)
		return INT_MAX;

	if (start <= root->start && end >= root->end)
		return root->max;

	return std::min(query(root->left, start, end), query(root->right, start, end));
}

std::vector<int> intervalMinNumber(std::vector<int> &A, std::vector<Interval> &queries) 
{
	std::vector<int> vec;
	SegmentTreeNode* root = build(A, 0, A.size() - 1);
	for (int i = 0; i < queries.size(); ++i)
		vec.push_back(query(root, queries[i].start, queries[i].end));
	return vec;
}