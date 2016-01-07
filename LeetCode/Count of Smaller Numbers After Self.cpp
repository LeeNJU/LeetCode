#include"TreeNode.h"
#include<vector>
//��Ŀ����:����һ�����飬���������[i + 1, n - 1]�б�nums[i]С�ĸ���
//�ⷨ����:�߶������߶��������䲻���Ǹ���
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

std::vector<int> countSmaller(std::vector<int>& nums)
{
	std::vector<int> result(nums.size(), 0);
	if (nums.empty())
		return result;

	int minimum = INT_MAX;
	int maximum = INT_MIN;
	for (int i = 0; i < nums.size(); ++i)//�ҵ����ֵ����Сֵ
	{
		if (nums[i] < minimum)
			minimum = nums[i];
		if (nums[i] > maximum)
			maximum = nums[i];
	}

	int increase = 0;//������ڸ�����Ҫ�Ѹ���ת�����������������߶�����ʱ����������[-1,0]�᲻ͣ�Ļ���
	if (minimum < 0)
		increase = -minimum;

	SegmentTreeNode* root = build(0, maximum + increase);
	for (int i = nums.size() - 1; i >= 0; --i)//�Ȳ�ѯ���޸�
	{
		result[i] = query(root, 0, nums[i] - 1 + increase);
		modify(root, nums[i] + increase);
	}

	return result;
}