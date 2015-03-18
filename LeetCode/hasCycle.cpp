#include"TreeNode.h"
//��Ŀ����������һ�������ж��Ƿ��л�
//�ⷨ����������ָ��slow��fast��slowÿ��ǰ��һ����fastÿ��ǰ����������������ܹ���ȣ��ͱ�ʾ�л�



bool hasCycle(ListNode* head)
{
	ListNode* slow = head, *fast = head;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (slow == fast)
			return true;
	}
	return false;
}