#include"TreeNode.h"
#include<vector>
//题目描述:给定一个数组和一组query，每个query求出数组中比这个值小的个数
//解法描述:构造一个线段树，count表示在区间[start,end]的个数，然后对每个queyr进行[0, val - 1]的查询
SegmentTreeNode* build(int start, int end)//构造线段树，count表示值在区间[start,end]内的个数
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

void modify(SegmentTreeNode* root, int val)//修改线段树，没出现一个val，就把count值加1
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

int query(SegmentTreeNode* root, int start, int end)//查询
{
	if (start > root->end || end < root->start)
		return 0;
	if (start <= root->start && root->end <= end)
		return root->count;

	return query(root->left, start, end) + query(root->right, start, end);
}

std::vector<int> countOfSmallerNumber(std::vector<int>& A, std::vector<int> &queries) 
{
	SegmentTreeNode* root = build(0, 10000);//构造一个0到10000的线段树，因为值不超过10000
	for (int i = 0; i < A.size(); ++i)//数组中每个元素更新线段树
		modify(root, A[i]);

	std::vector<int> result;
	for (int i = 0; i < queries.size(); ++i)
		result.push_back(query(root, 0, queries[i] - 1));
	
	return result;
}