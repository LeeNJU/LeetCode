#include"TreeNode.h"

using namespace std;


ListNode* rotateRight(ListNode* head, int k)
{
	if (head == nullptr || k <= 0)
		return head;
	ListNode* last = head;
	int length = 1;
	while (last->next)
	{
		++length;
		last = last->next;
	}

	if (length == k)
		return head;

	ListNode* first = head;
	int count = length - (k % length) - 1;
	while (count > 0)
	{
		first = first->next;
		--count;
	}

	last->next = head;
	ListNode* result = first->next;
	first->next = nullptr;
	return result;
}