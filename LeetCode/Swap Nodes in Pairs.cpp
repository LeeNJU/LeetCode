#include"TreeNode.h"
//��Ŀ����������һ������ÿ��������Ԫ�ؽ��н���������1->2->3->4�����2->1->4->3
//�ⷨ������ÿ�����ڵ�һ�ν��н�������

ListNode *swapPairs(ListNode *head) 
{
	if (!head || !head->next)//�ų��������ֻ��һ��Ԫ�ص����
		return head;

	ListNode dummy(0);//��һ��dummy�ڵ�
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
