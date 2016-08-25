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

//题目描述：给定一个链表，如果链表有环，则返回环的起始位置，否则返回null
//解法描述：两个指针ptr1和ptr2都指向head，ptr1走一步，ptr2走2步，二者重合的时候，让ptr1指向head，然后二者同时每次向后走一步，直到二者再次重合，即为解

ListNode *detectCycle(ListNode *head)
{
	if (head == nullptr)
		return nullptr;

	ListNode* ptr1 = head, *ptr2 = head;
	while (ptr2->next && ptr2->next->next)//ptr2走的快，只需要判断ptr2就可以了
	{
		ptr1 = ptr1->next;
		ptr2 = ptr2->next->next;
		if (ptr1 == ptr2)
		{
			ptr1 = head;
			while (ptr1 != ptr2)
			{
				ptr1 = ptr1->next;
				ptr2 = ptr2->next;
			}
			return ptr1;
		}
	}
	return nullptr;
}