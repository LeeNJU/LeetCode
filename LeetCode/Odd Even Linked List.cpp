#include"TreeNode.h"
//题目描述:给定一个链表，把序数为奇数的节点连在一起，序数为偶数的节点连在一起，最后奇数在前，偶数在后
//解法描述:用两个哨兵节点分别代表奇数节点和偶数节点
ListNode* oddEvenList(ListNode* head) 
{
	if (head == nullptr || head->next == nullptr)
		return head;

	ListNode o(0);
	ListNode e(0);
	ListNode* odd = &o;
	ListNode* even = &e;
	ListNode* current = head;//每次前进两位
	while (current && current->next)
	{
		odd->next = current;
		odd = odd->next;
		even->next = current->next;
		even = even->next;
		current = current->next->next;
	}

	if (current)
	{
		odd->next = current;
		odd = odd->next;
	}

	odd->next = e.next;
	even->next = nullptr;
	return o.next;
}