#include<iostream>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) { }
};

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
	{
		p = p->right;
	}
	p->right = rightSubtree;
	flatten(rightSubtree);//flatten右子树
}