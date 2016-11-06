#include"TreeNode.h"
//题目描述：给定一个链表，每相邻两个元素进行交换，例如1->2->3->4，变成2->1->4->3
//解法描述：每两个节点一次进行交换即可

ListNode *swapPairs(ListNode *head) 
{
	if (!head || !head->next)//排除空链表和只有一个元素的情况
		return head;

	ListNode dummy(0);//加一个dummy节点
	dummy.next = head;
	ListNode* prev = &dummy;

	while (head && head->next)
	{
		prev->next = head->next;
		head->next = prev->next->next;
		prev->next->next = head;
		prev = head;
		head = head->next;
	}

	return dummy.next;
}
