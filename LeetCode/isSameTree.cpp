#include"TreeNode.h"
//题目描述：给定两个二叉树，判断这两棵树是否相等
//解法描述：递归



bool isSameTree(TreeNode* p, TreeNode* q)
{
	if (p == nullptr && q == nullptr)//同时为null
		return true;

	if (p == nullptr || q == nullptr)//其中一个为null，但不同时为null
		return false;
	else if (p->val != q->val)
		return false;
	else
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);//必须左子树和右子树同时相等，所以是&&

}
