#include"TreeNode.h"
//题目描述:给定一个链表和两个值，如果这两个值在链表中存在，那么交换这两个节点，否则do nothing.不能交换节点的
//        值，必须交换节点
//解法描述:找到两个节点以及两个节点前一个节点的位置，然后交换，注意节点相邻的特殊情况

ListNode* swapNodes(ListNode* head, int v1, int v2) 
{
	ListNode dummy(0);
	dummy.next = head;

	ListNode* prev1 = &dummy, *prev2 = &dummy;
	ListNode* p1 = nullptr, *p2 = nullptr;
	ListNode* current = &dummy;
	while (current->next)
	{
		if (current->next->val == v1)
		{
			prev1 = current;
			p1 = current->next;
		}
		else if (current->next->val == v2)
		{
			prev2 = current;
			p2 = current->next;
		}

		current = current->next;
	}

	if (p1 == nullptr || p2 == nullptr || p1 == p2) //两个节点不存在或者指向同一个节点
		return dummy.next;

	if (p1->next == p2)//节点相邻，p1在p2前面
	{
		p1->next = p2->next;
		p2->next = p1;
		prev1->next = p2;
	}
	else if (p2->next == p1)//节点相邻，p2在p1前面
	{
		p2->next = p1->next;
		p1->next = p2;
		prev2->next = p1;
	}
	else
	{
		ListNode* t = p2->next;
		p2->next = p1->next;
		p1->next = t;
		prev2->next = p1;
		prev1->next = p2;
	}
	return dummy.next;
}