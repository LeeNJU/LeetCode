#include"TreeNode.h"
//题目描述：给定一个链表，如果链表有环，则返回环的起始位置，否则返回null
//解法描述：两个指针ptr1和ptr2都指向head，ptr1走一步，ptr2走2步，二者重合的时候，让ptr1指向head，然后二者同时每次向后走一步，直到二者再次重合，即为解

ListNode *detectCycle(ListNode *head)
{
	if (head == nullptr)
		return nullptr;

	ListNode* ptr1 = head, *ptr2 = head;
	while (ptr2->next != nullptr && ptr2->next->next != nullptr)//ptr2走的快，只需要判断ptr2就可以了
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
