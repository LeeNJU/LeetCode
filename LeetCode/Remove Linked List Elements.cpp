#include"TreeNode.h"
#include<limits.h>
//��Ŀ����������һ�������һ��ֵ��ɾ�����������ֵ��ȵ�Ԫ��
//�ⷨ�����������ڱ��ڵ㣬��������

ListNode* removeElements(ListNode* head, int val)
{
	ListNode node(INT_MIN);
	node.next = head;
	ListNode* p = &node;

	while (p->next)
	{
		if (p->next->val == val)//ɾ����ȵĽڵ㣬������Ҫ��pָ������ƶ�һλ
			p->next = p->next->next;
		else
			p = p->next;
	}
	return node.next;
}