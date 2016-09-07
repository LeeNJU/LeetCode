#include<algorithm>
#include<vector>
#include"TreeNode.h"
//题目描述：给定一个二叉树的先序遍历和中序遍历的结果，构造出整个二叉树
//解法描述：递归构造，先序遍历的第一个元素就是根节点，然后找到根节点在中序遍历的位置，确定左子树


TreeNode* build(std::vector<int>::iterator prefirst, std::vector<int>::iterator prelast,
	std::vector<int>::iterator infirst, std::vector<int>::iterator inlast)
{
	if (prefirst >= prelast || infirst >= inlast)
		return nullptr;

	TreeNode* root = new TreeNode(*prefirst);//先序节点的第一个元素为根节点
	std::vector<int>::iterator iter = find(infirst, inlast, root->val);//找到根节点在中序遍历中的位置

	std::vector<int>::iterator first = prefirst;
	advance(first, distance(infirst, iter));//找到左子树的长度和在先序遍历中的下标
	root->left = build(++prefirst, ++first, infirst, iter);//左子树递归调用

	root->right = build(first, prelast, ++iter, inlast);//右子树递归调用

	return root;
}

TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder)
{
	return build(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
}

