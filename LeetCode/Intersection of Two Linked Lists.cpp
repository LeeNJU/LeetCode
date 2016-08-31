#include"TreeNode.h"
//��Ŀ�������������������ҵ������������ཻ�Ľڵ�
//�ⷨ�����������������ĳ���A��B��������������A-B����Ȼ����������ͬʱ����ƶ����Ƶ�ͬһ���ڵ�ʱ���ǽ��

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
	int lengthA = 0, lengthB = 0;
	ListNode* pa = headA, *pb = headB;
	while (pa)//���������
	{
		++lengthA;
		pa = pa->next;
	}

	while (pb)
	{
		++lengthB;
		pb = pb->next;
	}

	pa = headA, pb = headB;
	if (lengthA >= lengthB)//�ϳ�������������ƶ�|lengthA - lengthB|��
	{
		int n = lengthA - lengthB;
		while (n)
		{
			pa = pa->next;
			--n;
		}
	}
	else
	{
		int n = lengthB - lengthA;
		while (n)
		{
			pb = pb->next;
			--n;
		}
	}

	while (pa != pb)//ֻҪ���߲���ȣ������ɨ��
	{
		pa = pa->next;
		pb = pb->next;
	}

	return pa;
}