#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

TreeNode* build(vector<int>::iterator prefirst, vector<int>::iterator prelast,
	vector<int>::iterator infirst, vector<int>::iterator inlast)
{
	if (prefirst >= prelast || infirst >= inlast)
		return nullptr;

	TreeNode* root = new TreeNode(*prefirst);
	vector<int>::iterator iter = find(infirst, inlast, root->val);

	vector<int>::iterator first = prefirst;
	advance(first, distance(infirst, iter));
	root->left = build(++prefirst, ++first, infirst, iter);

	root->right = build(first, prelast, ++iter, inlast);

	return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
	return build(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
}

