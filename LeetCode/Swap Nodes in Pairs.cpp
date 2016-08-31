#include"TreeNode.h"
//��Ŀ����������һ������ÿ��������Ԫ�ؽ��н���������1->2->3->4�����2->1->4->3
//�ⷨ������ÿ�����ڵ�һ�ν��н�������

ListNode *swapPairs(ListNode *head) 
{
	if (head == nullptr || head->next == nullptr)//�ų�ֻ��һ��Ԫ�غͿյ����
		return head;

	ListNode* p = head;
	head = head->next;  //���淵��ֵ  headָ��ԭ����ĵڶ���Ԫ��
	while (p != nullptr && p->next != nullptr)
	{
		ListNode* temp = p->next;
		p->next = temp->next;
		temp->next = p;

		ListNode* next = p->next;//����p��һ��Ԫ��
		if (p->next != nullptr && p->next->next != nullptr)//���������Ԫ�ص����
			p->next = p->next->next;
		p = next;
	}
	return head;
}
