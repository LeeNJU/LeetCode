#include"TreeNode.h"
#include<limits.h>
//��Ŀ��������������������������ϲ�
//�ⷨ���������һ���ڱ��ڵ㣬ʹ��ָ��l1�ĵ�һ���ڵ㣬Ȼ������ָ�����αȽϴ�С��ע��whileѭ��������Ҫ�ж���һ������Ϊ��

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
	if (l1 == nullptr || l2 == nullptr)
		return l1 == nullptr ? l2 : l1;

	ListNode dummy(INT_MIN);//�ڱ��ڵ㣬ָ��l1
	dummy.next = l1;
	ListNode* prev = &dummy;
	while (l1 && l2)//�ж������Ƿ�Ϊ��
	{
		if (l1->val <= l2->val)//l1��ֵ��l2��С����l1��prev����ƶ�һλ
		{
			l1 = l1->next;
		}
		else//l1��ֵl2�Ĵ󣬰�l2��ֵ�ϲ���l1֮ǰ
		{
			prev->next = l2;
			l2 = l2->next;
			prev->next->next = l1;
		}
		prev = prev->next;
	}

	if (!l1)
		prev->next = l2;
	return dummy.next;
}