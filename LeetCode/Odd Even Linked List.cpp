#include"TreeNode.h"
//��Ŀ����:����һ������������Ϊ�����Ľڵ�����һ������Ϊż���Ľڵ�����һ�����������ǰ��ż���ں�
//�ⷨ����:�������ڱ��ڵ�ֱ���������ڵ��ż���ڵ�
ListNode* oddEvenList(ListNode* head) 
{
	if (head == nullptr || head->next == nullptr)
		return head;

	ListNode o(0);
	ListNode e(0);
	ListNode* odd = &o;
	ListNode* even = &e;
	ListNode* current = head;//ÿ��ǰ����λ
	while (current && current->next)
	{
		odd->next = current;
		odd = odd->next;
		even->next = current->next;
		even = even->next;
		current = current->next->next;
	}

	if (current)
	{
		odd->next = current;
		odd = odd->next;
	}

	odd->next = e.next;
	even->next = nullptr;
	return o.next;
}