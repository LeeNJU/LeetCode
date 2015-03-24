#include"TreeNode.h"
//题目描述：给定一个链表，将其向右旋转k位，1->2->3->4->5->NULL旋转2位，4->5->1->2->3->NULL
//解法描述：直接调整链表，但注意k的值可能很大，当k是链表长度的倍数时，不需要旋转，此外k需要对长度取模


ListNode* rotateRight(ListNode* head, int k)
{
	if (head == nullptr || k <= 0)
		return head;

	int length = 1;
	ListNode* last = head;
	while (last->next)//求出长度,last指向最后一个元素，方便后面调整链表
	{
		++length;
		last = last->next;
	}

	if (k % length == 0)//k是链表长度的倍数，那么不用翻转链表
		return head;

	k = length - k % length - 1;//求出需要向后移动的步数
	ListNode* p = head;
	while (k--)
		p = p->next;

	ListNode* result = p->next;//调整链表
	p->next = nullptr;
	last->next = head;
	return result;
}