#include"TreeNode.h"
#include<vector>
//题目描述:给定一个数组，求出再区间[i + 1, n - 1]中比nums[i]小的个数
//解法描述:线段树，线段树的区间不能是负数
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

std::vector<int> countSmaller(std::vector<int>& nums)
{
	std::vector<int> result(nums.size(), 0);
	if (nums.empty())
		return result;

	int minimum = INT_MAX;
	int maximum = INT_MIN;
	for (int i = 0; i < nums.size(); ++i)//找到最大值和最小值
	{
		if (nums[i] < minimum)
			minimum = nums[i];
		if (nums[i] > maximum)
			maximum = nums[i];
	}

	int increase = 0;//如果存在负数，要把负数转换成正数，否则构造线段树的时候会出错，例如[-1,0]会不停的划分
	if (minimum < 0)
		increase = -minimum;

	SegmentTreeNode* root = build(0, maximum + increase);
	for (int i = nums.size() - 1; i >= 0; --i)//先查询后修改
	{
		result[i] = query(root, 0, nums[i] - 1 + increase);
		modify(root, nums[i] + increase);
	}

	return result;
}