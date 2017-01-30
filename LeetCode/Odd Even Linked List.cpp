#include"TreeNode.h"
//��Ŀ����:����һ������������Ϊ�����Ľڵ�����һ������Ϊż���Ľڵ�����һ�����������ǰ��ż���ں�
//�ⷨ����:�������ڱ��ڵ�ֱ���������ڵ��ż���ڵ�
ListNode* oddEvenList(ListNode* head) 
{
	ListNode even_dummy(0);
	ListNode odd_dummy(0);
	ListNode* even = &even_dummy;
	ListNode* odd = &odd_dummy;

	int count = 0;
	while (head)
	{
		++count;
		if (count % 2 == 1)
		{
			odd->next = head;
			odd = odd->next;
		}
		else
		{
			even->next = head;
			even = even->next;
		}

		head = head->next;
	}

	even->next = nullptr;
	odd->next = even_dummy.next;
	return odd_dummy.next;
}