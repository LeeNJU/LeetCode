#include"TreeNode.h"
#include<algorithm>
//题目描述:给定一个二叉树，找到其中包含的最大的二叉搜索树，也即节点最多
//解法描述:递归，对于当前节点，保存当前节点作为左子树的最大值，作为右子树的最小值，从左子树由下往上进行递归。

bool isValidBST(TreeNode* root, int& mn, int& mx, int& result) 
{
	if (!root) 
		return true;
    
	int left_n = 0, right_n = 0, left_mn = INT_MIN;
	int right_mn = INT_MIN, left_mx = INT_MAX, right_mx = INT_MAX;
	bool left = isValidBST(root->left, left_mn, left_mx, left_n);
	bool right = isValidBST(root->right, right_mn, right_mx, right_n);
	
	if (left && right) //左右子树同时存在
	{
		if ((!root->left || root->val >= left_mx) && (!root->right || root->val <= right_mn)) 
		{   //找到一个二叉搜索树
			result = left_n + right_n + 1;
			mn = root->left ? left_mn : root->val;
			mx = root->right ? right_mx : root->val;
			return true;
		}
	}
	result = std::max(left_n, right_n);
	return false;
}
int largestBSTSubtree(TreeNode* root)
{
	int result = 0, mn = INT_MIN, mx = INT_MAX;
	bool d = isValidBST(root, mn, mx, result);
	return result;
}