#include"TreeNode.h"
#include<vector>
//题目描述：合并k个已排序的链表
//解法描述；复用合并链表的函数,两两合并会超时，采用归并排序的思想

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
	if (l1 == nullptr || l2 == nullptr)
		return l1 == nullptr ? l2 : l1;

	ListNode dummy(INT_MIN);//哨兵节点，指向l1
	dummy.next = l1;
	ListNode* prev = &dummy;
	while (l1 && l2)//判断链表是否为空
	{
		if (l1->val <= l2->val)//l1的值比l2的小，则l1和prev向后移动一位
		{
			l1 = l1->next;
		}
		else//l1的值l2的大，把l2的值合并到l1之前
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

ListNode* merge(const std::vector<ListNode*>& lists, int first, int last)//利用归并排序的思想进行合并
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