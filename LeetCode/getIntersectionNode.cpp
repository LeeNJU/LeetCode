#include"TreeNode.h"
//题目描述：给定两个链表，找到这两个链表相交的节点
//解法描述：求出两个链表的长度A和B，长的链表先走A-B步，然后两个链表同时向后移动，移到同一个节点时就是结果

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
	int lengthA = 0, lengthB = 0;
	ListNode* pa = headA, *pb = headB;
	while (pa)//求出链表长度
	{
		++lengthA;
		pa = pa->next;
	}

	while (pb)
	{
		++lengthB;
		pb = pb->next;
	}

	pa = headA, pb = headB;
	if (lengthA >= lengthB)//较长的链表先向后移动|lengthA - lengthB|步
	{
		int n = lengthA - lengthB;
		while (n)
		{
			pa = pa->next;
			--n;
		}
	}
	else
	{
		int n = lengthB - lengthA;
		while (n)
		{
			pb = pb->next;
			--n;
		}
	}

	while (pa != pb)//只要二者不相等，就向后扫描
	{
		pa = pa->next;
		pb = pb->next;
	}

	return pa;
}