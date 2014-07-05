#include<iostream>
#include<vector>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr){}
};

TreeNode* build(int first, int last, const vector<int>& num)
{
	if (first > last)
		return nullptr;

	int middle = (first + last) / 2;
	TreeNode* root = new TreeNode(num[middle]);

	root->left = build(first, --middle, num);
	++middle;
	root->right = build(++middle, last, num);

	return root;
}

TreeNode* sortedArrayToBST(vector<int>& num)
{
	return build(0, num.size() - 1, num);
}