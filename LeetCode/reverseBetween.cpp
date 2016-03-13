#include"TreeNode.h"

//题目描述：给定一个链表，把从第m到n个节点进行反转
//解法描述：用一个哨兵节点，一遍扫描，依次把要反转的元素放到前面，
ListNode* reverseBetween(ListNode* head, int m, int n)
{
	ListNode dummy(-1);

	dummy.next = head;
	ListNode *prev_m = nullptr, *prev = &dummy; //prev_m指向第m个节点的前一个节点，prev指向第m个节点，head指向第m个节点下一个节点
	for (int i = 1; i <= n; ++i) 
	{
		if (i == m) 
			prev_m = prev;
		if (i > m && i <= n) // prev_m 和prev 静止不动
		{ 
			prev->next = head->next;
			head->next = prev_m->next;
			prev_m->next = head;
			head = prev;
		}
		prev = head;
		head = head->next;
	}
	return dummy.next;
}