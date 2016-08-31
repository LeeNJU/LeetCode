#include"TreeNode.h"
//��Ŀ����:����һ�����������ֵ�����������ֵ�������д��ڣ���ô�����������ڵ㣬����do nothing.���ܽ����ڵ��
//        ֵ�����뽻���ڵ�
//�ⷨ����:�ҵ������ڵ��Լ������ڵ�ǰһ���ڵ��λ�ã�Ȼ�󽻻���ע��ڵ����ڵ��������

ListNode* swapNodes(ListNode* head, int v1, int v2) 
{
	ListNode dummy(0);
	dummy.next = head;

	ListNode* prev1 = &dummy, *prev2 = &dummy;
	ListNode* p1 = nullptr, *p2 = nullptr;
	ListNode* current = &dummy;
	while (current->next)
	{
		if (current->next->val == v1)
		{
			prev1 = current;
			p1 = current->next;
		}
		else if (current->next->val == v2)
		{
			prev2 = current;
			p2 = current->next;
		}

		current = current->next;
	}

	if (p1 == nullptr || p2 == nullptr || p1 == p2) //�����ڵ㲻���ڻ���ָ��ͬһ���ڵ�
		return dummy.next;

	if (p1->next == p2)//�ڵ����ڣ�p1��p2ǰ��
	{
		p1->next = p2->next;
		p2->next = p1;
		prev1->next = p2;
	}
	else if (p2->next == p1)//�ڵ����ڣ�p2��p1ǰ��
	{
		p2->next = p1->next;
		p1->next = p2;
		prev2->next = p1;
	}
	else
	{
		ListNode* t = p2->next;
		p2->next = p1->next;
		p1->next = t;
		prev2->next = p1;
		prev1->next = p2;
	}
	return dummy.next;
}