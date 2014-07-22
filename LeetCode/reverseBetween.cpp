#include"TreeNode.h"

using namespace std;



ListNode* reverseBetween(ListNode* head, int m, int n)
{
	if (head == nullptr)
		return nullptr;

	ListNode* node = head, *p = nullptr, *q = nullptr;
	int count = 1;
	while (count <= n)
	{
		if (count == m)
			p = node;
		if (count == n)
			q = node;
		node = node->next;
		++count;
	}

	while (p != q)
	{
		int swap = q->val;
		q->val = p->val;
		p->val = swap;
		p = p->next;
		ListNode* tail = p;

		while (tail != q && tail->next != q)
		{
			tail = tail->next;
		}
		q = tail;
	}

	return head;
}