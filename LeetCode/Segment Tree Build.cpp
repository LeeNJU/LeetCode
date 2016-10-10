#include<vector>
#include<algorithm>
#include"TreeNode.h"
//题目描述:给定一个区间，构造一颗线段树
//解法描述:线段树的每个节点代表一个区间，对区间[start, end]进行划分，左子节点的区间为[start, mid], 右子节点的区间为
//        [mid + 1, end],其中mid = (start + end) / 2.
SegmentTreeNode* build(int start, int end) 
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
//题目描述:给定一个数组，构造一颗线段树，使得每个节点包含一段区间，和这个区间内的最大值
//解法描述:构造线段树的时候，先构造左右子节点，然后算出当前区间的最大值

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
	root->max = std::max(root->left->max, root->right->max);//算出左右子节点之后，才可以知道当前区间的最大值
}

SegmentTreeNode* build(std::vector<int>& A) 
{
	return build(A, 0, A.size() - 1);
}