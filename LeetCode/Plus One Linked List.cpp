#include"TreeNode.h"
//题目描述:给定一个链表表示一个数，例如1->2->3表示123，对这个数进行加1
//解法描述：先翻转链表，然后进行加1

ListNode* reverseList(ListNode* head)
{
	if (head == nullptr || head->next == nullptr)
		return head;

	ListNode node(-1);
	node.next = head;
	ListNode* p = head->next;//p指向要放到前面的节点
	while (p != nullptr)
	{
		head->next = p->next;
		p->next = node.next;
		node.next = p;
		p = head->next;
	}
	return node.next;
}

ListNode* plusOne(ListNode* head) 
{
	if (!head) 
		return head;
	
	ListNode *rev_head = reverseList(head), *cur = rev_head, *pre = cur;
	int carry = 1;
	while (cur) 
	{
		pre = cur;
		int val = cur->val + carry;
		cur->val = val % 10;
		carry = val / 10;
		if (carry == 0) 
			break;
		cur = cur->next;
	}
	if (carry) 
		pre->next = new ListNode(1);
	return reverseList(rev_head);
}