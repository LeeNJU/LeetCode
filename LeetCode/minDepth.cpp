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

int minDepth(TreeNode* root)
{
	if (root == nullptr)
		return 0;

	if (root->left == nullptr)
		return minDepth(root->right) + 1;
	else if (root->right == nullptr)
		return minDepth(root->left) + 1;
	else
		return min(minDepth(root->left), minDepth(root->right)) + 1;
}