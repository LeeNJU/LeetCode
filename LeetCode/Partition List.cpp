#include"TreeNode.h"
#include<limits.h>
//��Ŀ����������һ�������һ��ֵx���ָ�����ʹ�����б�xС��Ԫ����ǰ�棬��x����ߵ��ڵ�Ԫ���ں��棬����1->4->3->2->5->2��x=3��1->2->2->4->3->5
//�ⷨ�������߼��ϰ�����ֳ�������һ��������Ԫ�ر�xС����һ����Ԫ�ر�x��Ȼ����������������

ListNode *partition(ListNode *head, int x)
{
	if (!head)
		return head;

	ListNode left_dummy(INT_MIN);//�����ڱ��ڵ�ֱ��ʾ���������ͷ
	ListNode right_dummy(INT_MAX);

	ListNode* left_cur = &left_dummy;
	ListNode* right_cur = &right_dummy;
	while (head)//������������������Ԫ�ط��䵽��Ӧ��������
	{
		if (head->val < x)//��xС�����Ԫ�ط��䵽left������
		{
			left_cur->next = head;
			left_cur = head;
		}
		else//��x�󣬰�Ԫ�ط��䵽right������
		{
			right_cur->next = head;
			right_cur = head;
		}
		head = head->next;
	}

	right_cur->next = nullptr;//������Ľ�βҪ���
	left_cur->next = right_dummy.next;//���������ӵ�������

	return left_dummy.next;
}