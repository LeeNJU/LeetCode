#include"TreeNode.h"
//��Ŀ����������һ������Ҫ��ɾ��������n��Ԫ��
//�ⷨ���������һ���ڱ��ڵ㣬��������ȣ���ָ���ƶ���Ҫɾ����Ԫ�ص�ǰһ��Ԫ�أ�����ɾ��

ListNode* removeNthFromEnd(ListNode* head, int n)
{
	int length = 0;
	ListNode* node = head;
	while (node)//�������ĳ���
	{
		node = node->next;
		++length;
	}
	
	ListNode dummy(-1);
	dummy.next = head;
	ListNode* p = &dummy;
	while (length - n)//�ƶ�ָ�룬��ָ���Ƶ�Ҫɾ����Ԫ�ص�ǰһ��Ԫ��
	{
		p = p->next;
		--length;
	}

	p->next = p->next->next;
	return dummy.next;
}