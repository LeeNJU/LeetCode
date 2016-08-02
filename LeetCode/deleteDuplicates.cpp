#include"TreeNode.h"
#include<limits.h>
//��Ŀ����������һ����������ɾ�����е��ظ�Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ��
//�ⷨ����������ָ��prev��cur����prev��cur��Ԫ����ȵ�ʱ��prevָ��cur����һ��Ԫ��

ListNode *deleteDuplicates(ListNode *head) 
{
	if (head == nullptr)
		return nullptr;

	for (ListNode *prev = head, *cur = head->next; cur; cur = cur->next) 
	{
		if (prev->val == cur->val) 
		{
			prev->next = cur->next;
			delete cur;
		}
		else 
			prev = cur;
	}
	return head;
}


//�汾��������һ����������������ظ���Ԫ�أ��Ͱ������ظ���Ԫ��ɾ����1->2->3->3->4->4->5��ɾ����Ϊ1->2->5
//�ⷨ���������һ���ڱ��ڵ㣬����ָ��prev��cur�ֱ�ָ���ڱ��ڵ��ͷ�ڵ㣬2��ѭ������cur�����ظ�Ԫ��ʱ��ѭ��
//         ɾ���ظ�Ԫ��

ListNode *deleteDuplicate(ListNode *head)
{
	if (head == nullptr)
		return nullptr;

	ListNode dummy(INT_MIN);
	dummy.next = head;
	ListNode* prev = &dummy, *cur = head;
	while (cur)
	{
		bool duplicated = false;
		while (cur->next != nullptr && cur->val == cur->next->val)
		{
			duplicated = true;
			ListNode* temp = cur;
			cur = cur->next;
			delete temp;
		}
		if(duplicated) // ɾ���ظ������һ��Ԫ��
		{ 
			ListNode *temp = cur;
			cur = cur->next;
			delete temp;
			continue;
		}
		prev->next = cur;
		prev = prev->next;
		cur = cur->next;	
	}

	prev->next = cur;
	return dummy.next;
}