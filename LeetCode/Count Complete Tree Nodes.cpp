#include"TreeNode.h"
#include<algorithm>
//题目描述：给定一个满二叉树（除了最后一层之外，每一层都被填满了节点），计算节点的个数
//解法描述:不能完全只用递归，效率太低，调整递归的效率，针对根节点，算出根节点到左右两边最底层的高度，判断高度是否相等，
//        如果相等，是满二叉树，不等则递归计算

int getLeftHeight(TreeNode* r)//求出树的根节点到最左边的高度
{
	int height = 0;
	while (r)
	{
		++height;
		r = r->left;
	}
	return height;
}

int getRightHeight(TreeNode* r)
{
	int height = 0;
	while (r)
	{
		++height;
		r = r->right;
	}
	return height;
}

int countNodes(TreeNode* root)
{
	if (root == nullptr)
		return 0;

	int left = getLeftHeight(root);//注意这里传的是root
	int right = getRightHeight(root);
	if (left == right)
		return pow(2, left) - 1;
	else
		return countNodes(root->left) + countNodes(root->right) + 1;
}