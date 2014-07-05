#include<iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr){}
};

ListNode* removeNthFromEnd(ListNode* head, int n)
{
	if (head == nullptr)
		return nullptr;

	int length = 1;
	ListNode* p = head;
	while (p->next != nullptr)
	{
		++length;
		p = p->next;
	}

	if (length == n)
	{
		head = head->next;
		return head;
	}

	int count = length - n - 1;
	p = head;
	while (count > 0)
	{
		--count;
		p = p->next;
	}

	p->next = p->next->next;
	return head;
}