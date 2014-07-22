#include<iostream>
#include<vector>
#include<algorithm>
#include"TreeNode.h"
using namespace std;



TreeNode* build(vector<int>::iterator infirst, vector<int>::iterator inlast,
	vector<int>::iterator postfirst, vector<int>::iterator postlast)
{
	if (infirst >= inlast || postfirst >= postlast)
		return nullptr;

	TreeNode* root = new TreeNode(*--postlast);
	++postlast;

	vector<int>::iterator iter = find(infirst, inlast, root->val);
	vector<int>::iterator last = postfirst;
	advance(last, distance(infirst, iter));

	root->left = build(infirst, iter, postfirst, last);
	root->right = build(++iter, inlast, last, --postlast);
	return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
{
	return build(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());

}