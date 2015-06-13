#include"TreeNode.h"

//��Ŀ����������һ�������Ѵӵ�m��n���ڵ���з�ת
//�ⷨ��������һ���ڱ��ڵ㣬һ��ɨ�裬���ΰ�Ҫ��ת��Ԫ�طŵ�ǰ�棬
ListNode* reverseBetween(ListNode* head, int m, int n)
{
	ListNode dummy(-1);

	dummy.next = head;
	ListNode *prev_m, *prev = &dummy; //prev_mָ���m���ڵ��ǰһ���ڵ㣬prevָ���m���ڵ㣬headָ���m���ڵ���һ���ڵ�
	for (int i = 1; i <= n; ++i) 
	{
		if (i == m) 
			prev_m = prev;
		if (i > m && i <= n) // prev_m ��prev ��ֹ����
		{ 
			prev->next = head->next;
			head->next = prev_m->next;
			prev_m->next = head;
			head = prev;
		}
		prev = head;
		head = head->next;
	}
	return dummy.next;
}