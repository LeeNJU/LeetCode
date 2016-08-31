#include"TreeNode.h"
#include<limits.h>
//题目描述：给定一个链表和一个值，删除链表中与该值相等的元素
//解法描述：构造哨兵节点，遍历链表

ListNode* removeElements(ListNode* head, int val)
{
	ListNode node(INT_MIN);
	node.next = head;
	ListNode* p = &node;

	while (p->next)
	{
		if (p->next->val == val)//删除相等的节点，但不需要把p指针向后移动一位
			p->next = p->next->next;
		else
			p = p->next;
	}
	return node.next;
}