#include<algorithm>
#include"TreeNode.h"
using namespace std;


int maxDepth(TreeNode* root)
{
	if (root == nullptr)
		return 0;

	return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}
