#include"TreeNode.h"
#include<algorithm>
//题目描述:给定一个数组对应的线段树，现在对数组某个index的值进行修改，求修改后的线段树
//解法描述:递归，在当前区间判断，要修改的index是在左子节点还是右子节点
void modify(SegmentTreeNode* root, int index, int value) 
{
	if (!root || index > root->end || index < root->start)//没有交集
		return;

	if (root->start == root->end)//要修改的节点
	{
		root->max = value;
		return;
	}

	modify(root->left, index, value);
	modify(root->right, index, value);
	root->max = std::max(root->left->max, root->right->max);
}