#include<vector>
#include<algorithm>
#include"TreeNode.h"
//题目描述：给定一个二叉树的后序遍历和中序遍历结果，据此构造出整个二叉树
//解法描述：

TreeNode* build(std::vector<int>::iterator infirst, std::vector<int>::iterator inlast,
	std::vector<int>::iterator postfirst, std::vector<int>::iterator postlast)
{
	if (infirst >= inlast || postfirst >= postlast)
		return nullptr;

	TreeNode* root = new TreeNode(*--postlast);
	++postlast;

	std::vector<int>::iterator iter = find(infirst, inlast, root->val);
	std::vector<int>::iterator last = postfirst;
	advance(last, distance(infirst, iter));

	root->left = build(infirst, iter, postfirst, last);
	root->right = build(++iter, inlast, last, --postlast);
	return root;
}

TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder)
{
	return build(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());

}