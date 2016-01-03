#include"TreeNode.h"
#include<stack>
//题目描述:给定一颗二叉树，把它按照中序遍历转换成一个双端链表
//解法描述:用中序遍历，然后加上指针

DoublyListNode* bstToDoublyList(TreeNode* root) 
{
	if (root == nullptr)
		return nullptr;

	DoublyListNode head(0);
	DoublyListNode* prev = &head;
	std::stack<TreeNode*> s;
	while (root)
	{
		s.push(root);
		root = root->left;
	}

	while (!s.empty())
	{
		TreeNode* node = s.top();
		s.pop();

		DoublyListNode* n = new DoublyListNode(node->val);
		n->prev = prev;
		prev->next = n;
		prev = n;

		node = node->right;
		while (node)
		{
			s.push(node);
			node = node->left;
		}
	}

	head.next->prev = nullptr;
	return head.next;
}