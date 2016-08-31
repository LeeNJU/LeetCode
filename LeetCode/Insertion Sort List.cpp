#include"TreeNode.h"
#include<limits.h>
//题目描述：用插入排序的方法把链表排序
//解法描述：插入排序

ListNode* findInsertPos(ListNode *head, int x) 
{
	ListNode *pre = nullptr;
	for (ListNode *cur = head; cur != nullptr && cur->val <= x;
		pre = cur, cur = cur->next)
		;
	return pre;
}

ListNode *insertionSortList(ListNode *head) 
{
	ListNode dummy(INT_MIN);
	//dummy.next = head;
	for (ListNode *cur = head; cur != nullptr;) 
	{
		auto pos = findInsertPos(&dummy, cur->val);
		ListNode *tmp = cur->next;
		cur->next = pos->next;
		pos->next = cur;
		cur = tmp;
	}
	return dummy.next;
}

/*
ListNode *insertionSortList(ListNode *head)
{
	ListNode dummy(INT_MIN);
	dummy.next = head;
	for (ListNode* node = head, *first = &dummy; node != nullptr;)
	{
		if (node->val < first->val)
		{
			for (ListNode* listnode = &dummy; listnode != first; listnode = listnode->next)
			{
				if (listnode->next->val > node->val)
				{
					first->next = node->next;
					node->next = listnode->next;
					listnode->next = node;
					break;
				}
			}
			node = first->next;
		}
		else
		{
			first = first->next;
			node = node->next;
		}
	}
	return dummy.next;
}*/