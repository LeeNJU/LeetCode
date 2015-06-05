#include"TreeNode.h"
#include<limits.h>
//题目描述：给链表排序，要求复杂度为nlog(n)
//解法描述：归并排序

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
	if (l1 == nullptr || l2 == nullptr)
		return l1 == nullptr ? l2 : l1;

	ListNode dummy(INT_MIN);//哨兵节点，指向l1
	dummy.next = l1;
	ListNode* prev = &dummy;
	while (l1 && l2)//判断链表是否为空
	{
		if (l1->val <= l2->val)//l1的值比l2的小，则l1和prev向后移动一位
		{
			l1 = l1->next;
		}
		else//l1的值l2的大，把l2的值合并到l1之前
		{
			prev->next = l2;
			l2 = l2->next;
			prev->next->next = l1;
		}
		prev = prev->next;
	}

	if (!l1)
		prev->next = l2;
	return dummy.next;
}

ListNode* sortList(ListNode* head)
{
	if (head == nullptr || head->next == nullptr)
		return head;

	ListNode* slow = head, *fast = head;//快慢两个指针找到链表的中间节点
	while (fast->next != nullptr && fast->next->next != nullptr)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	
	fast = slow;
	slow = slow->next;
	fast->next = nullptr; //断开两个链表

	head = sortList(head);
	slow = sortList(slow);
	return mergeTwoLists(head, slow);
}
