#include"TreeNode.h"
#include<vector>
//��Ŀ�������ϲ�k�������������
//�ⷨ���������úϲ�����ĺ���,�����ϲ��ᳬʱ�����ù鲢�����˼��

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

ListNode* merge(const std::vector<ListNode*>& lists, int first, int last)//���ù鲢�����˼����кϲ�
{
	if (first < last)
	{
		int middle = (first + last) / 2;
		return mergeTwoLists(merge(lists, first, middle), merge(lists, middle + 1, last));
	}
	return lists[first];
}

ListNode* mergeKLists(std::vector<ListNode*>& lists)
{
	if (lists.size() == 0) 
		return nullptr;
    
	return merge(lists, 0, lists.size() - 1);
}