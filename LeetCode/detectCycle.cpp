#include"TreeNode.h"
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
