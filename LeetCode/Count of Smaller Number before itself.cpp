#include"TreeNode.h"
#include<vector>
//��Ŀ����:����һ������num�����������[0,i-1]֮�ڱ�num[i]С��Ԫ�صĸ�������������Ϊ[1,2,7,8,5], ��ôӦ�÷���
//        [0,1,2,3,2]
//�ⷨ����:����һ���߶�����ɨ������num���Ե�ǰԪ��num[i],�Ȳ�ѯ����[0, num[i] - 1],Ȼ���޸��߶���
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

std::vector<int> countOfSmallerNumberII(std::vector<int>& A) 
{
	SegmentTreeNode* root = build(0, 10000);
	
	std::vector<int> result;
	for (int i = 0; i < A.size(); ++i)//�Ȳ�ѯ���޸�
	{
		result.push_back(query(root, 0, A[i] - 1));
		modify(root, A[i]);
	}

	return result;
}