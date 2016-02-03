#include"TreeNode.h"
#include<vector>
//题目描述:给定一个数组和一些query和modify命令，query求出区间(start, end)的和，modify修改区间(index,value)
//        index的值
//解法描述:线段树和单点更新
class Solution
{
private:
	SegmentTreeNode* root;
	SegmentTreeNode* build(const std::vector<int>& num, int start, int end)//根据数组创建线段树
	{
		if (start > end)
			return nullptr;
		if (start == end)
		{
			SegmentTreeNode* node = new SegmentTreeNode(start, end);
			node->max = num[start];
			return node;
		}

		SegmentTreeNode* node = new SegmentTreeNode(start, end);
		int mid = (start + end) / 2;
		node->left = build(num, start, mid);
		node->right = build(num, mid + 1, end);
		node->max = node->left->max + node->right->max;
		return node;
	}

	long long query(SegmentTreeNode* node, int start, int end)//查询某个区间
	{
		if (end < node->start || start > node->end)
			return 0;
		if (start <= node->start && end >= node->end)
			return node->max;

		long long num1 = query(node->left, start, end);
		long long num2 = query(node->right, start, end);
		return num1 + num2;
	}

	void modify(SegmentTreeNode* node, int index, int value)//修改某个点的值
	{
		if (index < node->start || index > node->end)
			return;
		if (node->start == node->end)
		{
			node->max = value;
			return;
		}

		int mid = (node->start + node->end) / 2;
		modify(node->left, index, value);
		modify(node->right, index, value);
		node->max = node->left->max + node->right->max;
	}
public:
	Solution(std::vector<int> A)
	{
		this->root = build(A, 0, A.size() - 1);
	}

	long long query(int start, int end)
	{
		return query(root, start, end);
	}

	void modify(int index, int value)
	{
		modify(root, index, value);
	}
};