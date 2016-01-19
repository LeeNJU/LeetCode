#include"TreeNode.h"
#include<vector>
//bugs
SegmentTreeNode* build(std::vector<int>& nums, int start, int end, int lower, int upper)
{
	if (end < start)
		return nullptr;

	SegmentTreeNode* root = new SegmentTreeNode(start, end);
	if (start == end)
	{
		root->sum = nums[start];
		if (root->sum <= upper && root->sum >= lower)
			root->count = 1;
		else
			root->count = 0;
		return root;
	}

	int mid = (start + end) / 2;
	root->left = build(nums, start, mid, lower, upper);
	root->right = build(nums, mid + 1, end, lower, upper);
	root->sum = root->left->sum + root->right->sum;
	root->count = root->left->count + root->right->count;
	if (root->sum <= upper && root->sum >= lower)
		root->count++;
	return root;
}

int countRangeSum(std::vector<int>& nums, int lower, int upper)
{
	if (nums.empty())
		return 0;

	SegmentTreeNode* root = build(nums, 0, nums.size() - 1, lower, upper);
	return root->count;
}