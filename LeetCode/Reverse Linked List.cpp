#include"TreeNode.h"

//题目描述：反转单链表
//解法描述：用一个哨兵节点，依次把第二，三，四等个节点放到哨兵节点后面，1->2->3->4->5->6, 2->1->3->4->5->6, 3->2->1->4->5->6,....

ListNode* reverseList(ListNode* head)
{
	if (head == nullptr || head->next == nullptr)
		return head;

	ListNode node(-1);
	node.next = head;
	ListNode* p = head->next;//p指向要放到前面的节点
	while (p != nullptr)
	{
		head->next = p->next;
		p->next = node.next;
		node.next = p;
		p = head->next;
	}
	return node.next;
}

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