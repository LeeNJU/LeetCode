#include"TreeNode.h"

//��Ŀ����������һ�������һ��ֵk��ÿk���ڵ����һ�η�ת������1->2->3->4->5��k=3������3->2->1->4->5
//�ⷨ������

ListNode* reverseList(ListNode* head)
{
	if (head == nullptr || head->next == nullptr)
		return head;

	ListNode node(-1);
	node.next = head;
	ListNode* p = head->next;//pָ��Ҫ�ŵ�ǰ��Ľڵ�
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
		ListNode* first = p;//����һ��group��ĵ�һ���ڵ㣬��ת֮�����һ��group�����һ���ڵ�
		while (count && p != nullptr)//�ҵ�Ҫ��ת������group
		{
			p = p->next;
			--count;
		}

		if (p != nullptr)
		{
			ListNode* q = p->next;
			p->next = nullptr;//������Ľڵ�Ͽ�
			reverseList(first);
			first->next = q;
			p = q;
		}
	}
}