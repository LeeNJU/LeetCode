#include"TreeNode.h"
//题目描述：给定一个链表，完成下列操作：L0->L1->L2->L3...->Ln,转换成L0->Ln->L1->Ln-1...
//解法描述；找到链表的中间，分成两个子链表，将后一半链表逆转，然后再合并两个子链表

ListNode* reverse(ListNode* head)
{
	if (head == nullptr || head->next == nullptr)
		return head;

	ListNode* cur = head->next, *tail = head;
	while (cur)
	{
		tail->next = cur->next;
		cur->next = head;
		head = cur;
		cur = tail->next;
	}
	return head;
}

void reorderList(ListNode *head)
{
	if (head == nullptr || head->next == nullptr)
		return;

	ListNode* slow = head, *fast = head, *prev = head;//一个慢指针，一个快指针
	while (fast && fast->next)
	{
		prev = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	prev->next = nullptr;//分成两段，前一段链表的末尾设为null，slow指向后半段链表开头

	slow = reverse(slow);//反转后半段链表

	ListNode* cur = head;
	while (cur->next)//合并两个链表,注意循环结束条件
	{
		ListNode* temp = cur->next;
		cur->next = slow;
		slow = slow->next;
		cur->next->next = temp;
		cur = temp;
	}
	cur->next = slow;
}