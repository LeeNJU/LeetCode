#include<iostream>
#include<vector>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL){}
};

TreeNode* build(ListNode* first, ListNode* last, int length)
{
	if (first->val > last->val || first == NULL || last == NULL)
		return NULL;

	if (first == last)
		return new TreeNode(first->val);

	ListNode* p = first;
	int index = length / 2;
	while (index > 0)
	{
		p = p->next;
		--index;
	}

	TreeNode* root = new TreeNode(p->val);

	ListNode* node = first;
	if (node == p)
		node = NULL;
	else
	{
		while (node->next != p)
		{
			node = node->next;
		}
	}
	root->left = build(first, node, length / 2);
	root->right = build(p->next, last, length - length / 2 - 1);

	return root;
}

TreeNode* sortedListToBST(ListNode* head)
{
	if (head == nullptr)
		return nullptr;

	if (head->next == nullptr)
		return new TreeNode(head->val);

	int length = 0;
	ListNode* tail = head;
	while (tail->next != nullptr)
	{
		tail = tail->next;
		++length;
	}

	return build(head, tail, length);
}