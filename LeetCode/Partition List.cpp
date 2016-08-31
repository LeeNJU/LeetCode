#include"TreeNode.h"
#include<limits.h>
//题目描述：给定一个链表和一个值x，分割链表，使得所有比x小的元素在前面，比x大或者等于的元素在后面，例如1->4->3->2->5->2，x=3，1->2->2->4->3->5
//解法描述：逻辑上把链表分成两条，一条的所有元素比x小，另一条的元素比x大，然后这两条链表相连

ListNode *partition(ListNode *head, int x)
{
	if (!head)
		return head;

	ListNode left_dummy(INT_MIN);//两个哨兵节点分别表示两条链表的头
	ListNode right_dummy(INT_MAX);

	ListNode* left_cur = &left_dummy;
	ListNode* right_cur = &right_dummy;
	while (head)//遍历这个链表，把链表的元素分配到对应的链表中
	{
		if (head->val < x)//比x小，则把元素分配到left链表中
		{
			left_cur->next = head;
			left_cur = head;
		}
		else//比x大，把元素分配到right链表中
		{
			right_cur->next = head;
			right_cur = head;
		}
		head = head->next;
	}

	right_cur->next = nullptr;//右链表的结尾要清空
	left_cur->next = right_dummy.next;//右链表连接到左链表

	return left_dummy.next;
}