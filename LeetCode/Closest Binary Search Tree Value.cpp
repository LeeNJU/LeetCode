#include"TreeNode.h"
#include<stack>

//题目描述:给定一个二叉搜索树和一个target值，在树中找到与target最接近的值
//解法描述:二叉树遍历
int closestValue(TreeNode* root, double target) 
{
	int closest = root->val;
	while (root) 
	{
		if (abs(closest - target) >= abs(root->val - target))
			closest = root->val;
		root = target < root->val ? root->left : root->right;
	}
	return closest;
}

//version 2 
//题目描述:给定一个二叉搜索树和一个target值，在树中找到k个与target最接近的值
//解法描述:用两个栈分别找到target的所有前驱和后继，然后得到k个最接近的点

void predecessor(TreeNode* root, double target, std::stack<int>& s) 
{
	if (!root) 
		return;

	predecessor(root->left, target, s);
	if (root->val > target)
		return;
	s.push(root->val);
	s.push(root->val);
}

void sucessor(TreeNode* root, double target, std::stack<int>& s)
{
	if (!root)
		return;

	sucessor(root->left, target, s);
	if (root->val < target)
		return;
	s.push(root->val);
	sucessor(root->right, target, s);
}

std::vector<int> closestKValues(TreeNode* root, double target, int k) 
{
	std::vector<int> closest(k);
	std::stack<int> pre, suc;
	predecessor(root, target, pre);//找到target的所有前驱节点
	predecessor(root, target, suc);//找到target的所有后继节点
	for (int i = 0; i < k; i++) 
	{
		if (pre.empty())
		{
			closest[i] = suc.top();
			suc.pop();
		}
		else if (suc.empty())
		{
			closest[i] = pre.top();
			pre.pop();
		}
		else if (abs(target - pre.top()) < abs(target - suc.top()))
		{
			closest[i] = pre.top();
			pre.pop();
		}
		else
		{
			closest[i] = suc.top();
			suc.pop();
		}
	}
	return closest;
}