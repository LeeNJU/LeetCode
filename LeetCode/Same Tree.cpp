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

/*
用两个queue进行层次遍历，
bool isSameTree(TreeNode* p, TreeNode* q)
{
	if(!p && !q)
		return true;
	if(!p || !q)
		return false;

	TreeNode *left, *right;

	std::queue<TreeNode*> q1, q2;
	q1.push(p);
	q2.push(q);
	while (!q1.empty() && !q2.empty())
	{
		left = q1.front();
		q1.pop();
		right = q2.front();
		q2.pop();

		if (left == nullptr && right == nullptr)
			continue;
		if (left == nullptr || right == nullptr || left->val != right->val)
			return false;
		
		q1.push(left->left);
		q1.push(left->right);
		q2.push(right->left);
		q2.push(right->right);
	}

	return true;
}
*/