#include<iostream>
#include<algorithm>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

int depth(TreeNode* root)
{
	if (root == nullptr)
		return 0;

	return max(depth(root->left), depth(root->right)) + 1;
}

bool isBalanced(TreeNode* root)
{
	if (root == nullptr)
		return true;
	if (abs(depth(root->left) - depth(root->right)) > 1)
		return false;

	return isBalanced(root->left) && isBalanced(root->right);
}