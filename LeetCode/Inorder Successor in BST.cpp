#include"TreeNode.h"
//题目描述:给定一个二叉搜索树和一个节点，找到这个节点在中序遍历中的后继节点
//解法描述:如果p的有右子节点，那么后继就是右子树的最左边的节点，如果p没有右子节点，遍历整个二叉树，保存可能的后继点，root
//        的值比p大，往左子树走，那么root可能是后继节点，如果root比p大，往右子树走，不更新后继节点，因为不可能是后继点

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) 
{
	if (p->right)
	{
		TreeNode* node = p->right;
		while (node->left)
			node = node->left;
		return node;
	}

	TreeNode* successor = nullptr;
	while (root) 
	{
		if (p->val < root->val)//往左子树走，root可能是后继节点
		{
			successor = root;
			root = root->left;
		}
		else if (p->val > root->val)//往右子树走，不需要更新后继节点
			root = root->right;
		else 
			break;
	}
	return successor;
}