#include"TreeNode.h"
//题目描述：给定一个链表，要求删除倒数第n个元素
//解法描述：添加一个哨兵节点，求出链表长度，把指针移动到要删除的元素的前一个元素，进行删除


ListNode* removeNthFromEnd(ListNode* head, int n)
{
	int length = 0;
	ListNode* node = head;
	while (node)//求出链表的长度
	{
		node = node->next;
		++length;
	}
	
	ListNode dummy(-1);
	dummy.next = head;
	ListNode* p = &dummy;
	while (length - n)//移动指针，把指针移到要删除的元素的前一个元素
	{
		p = p->next;
		--length;
	}

	p->next = p->next->next;
	return dummy.next;
}