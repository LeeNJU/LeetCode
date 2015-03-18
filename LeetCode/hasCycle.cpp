#include"TreeNode.h"
//题目描述：给定一个链表，判断是否有环
//解法描述：两个指针slow和fast，slow每次前进一步，fast每次前进两步，如果二者能够相等，就表示有环



bool hasCycle(ListNode* head)
{
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