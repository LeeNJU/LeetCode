#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

bool hasPathSum(TreeNode* root, int sum)
{
	if (root == nullptr)
		return false;

	if (root->left == nullptr && root->right == nullptr)
	{
		if (root->val == sum)
			return true;
		else
			return false;
	}
	return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}