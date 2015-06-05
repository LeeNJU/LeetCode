#include"TreeNode.h"
#include<limits.h>
//��Ŀ����������������Ҫ���Ӷ�Ϊnlog(n)
//�ⷨ�������鲢����

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

ListNode* sortList(ListNode* head)
{
	if (head == nullptr || head->next == nullptr)
		return head;

	ListNode* slow = head, *fast = head;//��������ָ���ҵ�������м�ڵ�
	while (fast->next != nullptr && fast->next->next != nullptr)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	
	fast = slow;
	slow = slow->next;
	fast->next = nullptr; //�Ͽ���������

	head = sortList(head);
	slow = sortList(slow);
	return mergeTwoLists(head, slow);
}
