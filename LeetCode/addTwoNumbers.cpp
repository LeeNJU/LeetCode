#include<iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) 
{
	if (l1 == nullptr)
		return l2;
	if (l2 == nullptr)
		return l1;

	int temp = 0;
	ListNode* head = nullptr, *p = nullptr;
	while (l1 != nullptr || l2 != nullptr)
	{
		int add1 = 0, add2 = 0;
		if (l1 != nullptr)
			add1 = l1->val;
		if (l2 != nullptr)
			add2 = l2->val;

		if (p == nullptr)
		{
			p = new ListNode((add1 + add2 + temp) % 10);
			head = p;
		}
		else
		{
			p->next = new ListNode((add1 + add2 + temp) % 10 );
			p = p->next;
		}

		temp = (add1 + add2 + temp) / 10;
		if (l1 != nullptr)
			l1 = l1->next;
		if (l2 != nullptr)
			l2 = l2->next;
	}

	if (temp)
	{
		p->next = new ListNode(temp);
	}
	return head;
}