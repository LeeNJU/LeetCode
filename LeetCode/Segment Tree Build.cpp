#include<vector>
#include<algorithm>
#include"TreeNode.h"
//��Ŀ����:����һ�����䣬����һ���߶���
//�ⷨ����:�߶�����ÿ���ڵ����һ�����䣬������[start, end]���л��֣����ӽڵ������Ϊ[start, mid], ���ӽڵ������Ϊ
//        [mid + 1, end],����mid = (start + end) / 2.
SegmentTreeNode * build(int start, int end) 
{
	if (start > end)
		return nullptr;
	if (start == end)
		return new SegmentTreeNode(start, start);

	int mid = (start + end) / 2;
	SegmentTreeNode* root = new SegmentTreeNode(start, end);
	root->left = build(start, mid);
	root->right = build(mid + 1, end);
	return root;
}

//version 2
//��Ŀ����:����һ�����飬����һ���߶�����ʹ��ÿ���ڵ����һ�����䣬����������ڵ����ֵ
//�ⷨ����:�����߶�����ʱ���ȹ��������ӽڵ㣬Ȼ�������ǰ��������ֵ

SegmentTreeNode* build(std::vector<int>& num, int start, int end)
{
	if (start > end)
		return nullptr;
	if (start == end)
	{
		SegmentTreeNode* node = new SegmentTreeNode(start, start);
		node->max = num[start];
		return node;
	}

	SegmentTreeNode* root = new SegmentTreeNode(start, end);
	int mid = (start + end) / 2;
	root->left = build(num, start, mid);
	root->right = build(num, mid + 1, end);
	root->max = std::max(root->left->max, root->right->max);//��������ӽڵ�֮�󣬲ſ���֪����ǰ��������ֵ
}

SegmentTreeNode* build(std::vector<int>& A) 
{
	return build(A, 0, A.size() - 1);
}