#include"TreeNode.h"

//题目描述：给定一个链表和一个值k，每k个节点进行一次反转，例如1->2->3->4->5，k=3，返回3->2->1->4->5
//解法描述：用一个哨兵节点，每k个元素进行反转

ListNode* reverse(ListNode* prev, ListNode* first, ListNode* last) //first和last之间的元素需要反转，返回反转后的最后一个节点指针
{
	ListNode* start = first;// 保存反转后最后一个节点的指针
	while (first != last)//反转链表，依次把first到last区间的元素进行反转，last向左移动
	{
		prev->next = first->next;
		ListNode* p = last->next;
		first->next = p;
		last->next = first;
		first = prev->next;
	}
	return start;
}

ListNode* reverseKGroup(ListNode* head, int k)
{
	if (head == nullptr || head->next == nullptr || k < 2) //排除特殊情况
		return head;

	ListNode dummy(-1);
	dummy.next = head;
	for (ListNode *prev = &dummy, *end = head; end; end = prev->next) 
	{
		for (int i = 1; i < k && end; ++i) //end指针向后移动k-1位
			end = end->next;
		if (end == nullptr) // 不足k 个
			break; 
		prev = reverse(prev, prev->next, end); //prev，prev->next和end都不为null
	}
	return dummy.next;
}