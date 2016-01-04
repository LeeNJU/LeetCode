#include"TreeNode.h"
#include<algorithm>
//题目描述:给定一个数组对应的线段树，每个节点存储了当前区间内的最大值，给定一个区间，找到这个区间内的最大值
//解法描述:递归
int query(SegmentTreeNode* root, int start, int end) 
{
	if (end < root->start || start > root->end)//没有交集
		return INT_MIN;
	if (start <= root->start && end >= root->end)//区间[start, end]包含了当前节点的区间
		return root->max;

	int num1 = query(root->left, start, end);//在左子节点进行查询
	int num2 = query(root->right, start, end);//在右子节点进行查询
	if (num1 == INT_MIN)//与坐子节点没有交集
		return num2;
	else if (num2 == INT_MIN)//与右子节点没有交集
		return num1;
	else
		return std::max(num1, num2);//取最大值
}

//version 2
//题目描述:给定一个数组对应的线段树，每个节点包含这个数组中值在当前区间的个数，给定一个查询区间，求出在这个区间范围内的个数
//解法描述:由于每个节点存的是个数，分别在左右节点查询然后求和

int query2(SegmentTreeNode *root, int start, int end) 
{	
	if (!root || end < root->start || start > root->end)//没有交集
		return 0;
	if (start <= root->start && end >= root->end)//区间[start, end]包含了当前节点的区间
		return root->count;

	return query(root->left, start, end) + query(root->right, start, end);//分别在左右节点查询，结果进行求和
}