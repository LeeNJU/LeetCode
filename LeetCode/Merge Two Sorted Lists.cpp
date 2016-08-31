#include"TreeNode.h"
#include<limits.h>
//题目描述：给定两个已序链表，将其合并
//解法描述：添加一个哨兵节点，使其指向l1的第一个节点，然后两个指针依次比较大小，注意while循环结束后，要判断哪一个链表为空

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