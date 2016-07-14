#include"TreeNode.h"
//��Ŀ����:����һ�������ʾһ����������1->2->3��ʾ123������������м�1
//�ⷨ�������ȷ�ת����Ȼ����м�1

ListNode* reverseList(ListNode* head)
{
	if (head == nullptr || head->next == nullptr)
		return head;

	ListNode node(-1);
	node.next = head;
	ListNode* p = head->next;//pָ��Ҫ�ŵ�ǰ��Ľڵ�
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