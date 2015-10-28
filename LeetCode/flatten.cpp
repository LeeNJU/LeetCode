#include"TreeNode.h"
//题目描述：给定一个二叉树，将其扁平化成一个链表，即把左子节点连接到父节点的右指针上，右子节点连接到左子节点的右指针上
//解法描述：递归，先扁平化左子树，然后扁平化右子树

void flatten(TreeNode* root)//把二叉树扁平化
{
	if (root == nullptr)
		return;

	TreeNode* rightSubtree = root->right;//记录右子树
	root->right = root->left;//左子树移到右节点
	root->left = nullptr;
	flatten(root->right);//flatten左子树

	TreeNode* p = root;
	while (p->right != nullptr)
		p = p->right;
	
	p->right = rightSubtree;
	flatten(rightSubtree);//flatten右子树
}