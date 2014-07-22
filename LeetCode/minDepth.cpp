#include<iostream>
#include<algorithm>
#include"TreeNode.h"
using namespace std;


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