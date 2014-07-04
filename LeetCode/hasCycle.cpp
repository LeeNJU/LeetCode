#include<iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr){}
};

bool hasCycle(ListNode* head)
{
	if (head == nullptr)
		return false;

	ListNode* slow = head, *fast = head;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (slow == fast)
			return true;
	}
	return false;
}