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

//��Ŀ����������һ��������������л����򷵻ػ�����ʼλ�ã����򷵻�null
//�ⷨ����������ָ��ptr1��ptr2��ָ��head��ptr1��һ����ptr2��2���������غϵ�ʱ����ptr1ָ��head��Ȼ�����ͬʱÿ�������һ����ֱ�������ٴ��غϣ���Ϊ��

ListNode *detectCycle(ListNode *head)
{
	if (head == nullptr)
		return nullptr;

	ListNode* ptr1 = head, *ptr2 = head;
	while (ptr2->next && ptr2->next->next)//ptr2�ߵĿ죬ֻ��Ҫ�ж�ptr2�Ϳ�����
	{
		ptr1 = ptr1->next;
		ptr2 = ptr2->next->next;
		if (ptr1 == ptr2)
		{
			ptr1 = head;
			while (ptr1 != ptr2)
			{
				ptr1 = ptr1->next;
				ptr2 = ptr2->next;
			}
			return ptr1;
		}
	}
	return nullptr;
}