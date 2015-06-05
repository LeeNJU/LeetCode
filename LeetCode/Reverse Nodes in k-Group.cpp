#include"TreeNode.h"

//题目描述：给定一个链表和一个值k，每k个节点进行一次反转，例如1->2->3->4->5，k=3，返回3->2->1->4->5
//解法描述：

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

ListNode* reverseKGroup(ListNode* head, int k)
{
	if (!head)
		return head;

	ListNode* p = head;
	while (p)
	{
		int count = k - 1;
		ListNode* first = p;//保存一个group里的第一个节点，反转之后就是一个group的最后一个节点
		while (count && p != nullptr)//找到要反转的链表group
		{
			p = p->next;
			--count;
		}

		if (p != nullptr)
		{
			ListNode* q = p->next;
			p->next = nullptr;//跟后面的节点断开
			reverseList(first);
			first->next = q;
			p = q;
		}
	}
}