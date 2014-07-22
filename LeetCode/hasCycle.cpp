#include"TreeNode.h"
using namespace std;



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