#include<algorithm>
#include"TreeNode.h"
using namespace std;



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