#include"TreeNode.h"
#include<stack>
//��Ŀ����:����һ�Ŷ����������������������ת����һ��˫������
//�ⷨ����:�����������Ȼ�����ָ��

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