#include"TreeNode.h"
//题目描述:删除二叉搜索树中的一个节点
//解法描述:递归

TreeNode* deleteNode(TreeNode* root, int key)
{
	if (root == nullptr)
		return nullptr;

	if (root->val < key)
		root->right = deleteNode(root->right, key);
	else if (root->val > key)
		root->left = deleteNode(root->left, key);
	else
	{
		if (root->right)
		{
			TreeNode* node = root->right;
			while (node->left)
				node = node->left;

			root->val = node->val;
			root->right = deleteNode(root->right, node->val);
		}
		else if (root->left)
		{
			TreeNode* node = root->left;
			while (node->right)
				node = node->right;

			root->val = node->val;
			root->left = deleteNode(root->left, node->val);
		}
		else
			return nullptr;
	}
	return root;
}