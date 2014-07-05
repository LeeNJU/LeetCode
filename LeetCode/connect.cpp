#include<iostream>

using namespace std;

struct TreeLinkNode
{
	int val;
	TreeLinkNode* left, *right, *next;
	TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr){}
};


void connects(TreeLinkNode* root, TreeLinkNode* next)
{
	if (root == nullptr)
		return;
	if (root->left == nullptr && root->right == nullptr)
	{
		root->next = next;
		return;
	}

	root->left->next = root->right;
	if (next != nullptr)
		root->right->next = next->left;
	else
		root->right->next = nullptr;
	connects(root->left, root->left->next);
	connects(root->right, root->right->next);

}
void connect(TreeLinkNode* root)
{
	connects(root, nullptr);
}