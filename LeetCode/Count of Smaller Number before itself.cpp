#include"TreeNode.h"
#include<vector>
//题目描述:给定一个数组num，求出在区间[0,i-1]之内比num[i]小的元素的个数，例如数组为[1,2,7,8,5], 那么应该返回[0,1,2,3,2]
//解法描述:构造一个线段树，扫描数组num，对当前元素num[i],先查询区间[0, num[i] - 1],然后修改线段树
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

std::vector<int> countOfSmallerNumberII(std::vector<int>& A) 
{
	SegmentTreeNode* root = build(0, 10000);
	
	std::vector<int> result;
	for (int i = 0; i < A.size(); ++i)//先查询后修改
	{
		result.push_back(query(root, 0, A[i] - 1));
		modify(root, A[i]);
	}

	return result;
}