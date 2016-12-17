#include"TreeNode.h"
#include<queue>
//题目描述：给定一个二叉树，判断其是否是镜面对称的
//解法描述：要判断是否镜面对称，必须从左右子树分别判断，所以另写一个函数，参数为左子树和右子树，然后递归判断

bool symmetric(TreeNode* left, TreeNode* right)
{
	if (left == nullptr && right == nullptr)
		return true;

	if (left == nullptr || right == nullptr)
		return false;
	else if (left->val != right->val)
		return false;
	else
		return symmetric(left->left, right->right) && symmetric(left->right, right->left);
}

bool isSymmetric(TreeNode* root)
{
	if (root == nullptr)
		return true;

	return symmetric(root->left, root->right);
}

/*
用两个queue进行层次遍历，
bool isSymmetric(TreeNode* root)
{
	TreeNode *left, *right;
	if (!root)
		return true;

	std::queue<TreeNode*> q1, q2;
	q1.push(root->left);
	q2.push(root->right);
	while (!q1.empty() && !q2.empty())
	{
		left = q1.front();
		q1.pop();
		right = q2.front();
		q2.pop();
		if (left == nullptr && right == nullptr)
			continue;
		if (left == nullptr || right == nullptr)
			return false;
		if (left->val != right->val)
			return false;
		q1.push(left->left);
		q1.push(left->right);
		q2.push(right->right);
		q2.push(right->left);
	}
	return true;
}*/