#include"TreeNode.h"

//题目描述：给定一个链表，判断其是否是Palindrome
//解法描述：把链表从中间断开，分成两半，把后一半链表反转，然后依次比较

ListNode* reverse(ListNode* head) //反转链表
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

bool isPalindrome(ListNode* head) {
	if (head == nullptr || head->next == nullptr)
		return true;

	ListNode* slow = head, *fast = head;
	ListNode dummy(0);
	dummy.next = head;
	ListNode* prev = &dummy;
	while (fast && fast->next)//快慢指针断开链表
	{
		prev = prev->next;
		slow = slow->next;
		fast = fast->next->next;
	}

	fast = reverse(slow);
	slow = head;
	prev->next = nullptr;
	bool result = true;
	ListNode* subhead = fast;
	while (slow)
	{
		if (slow->val != fast->val)
		{
			result = false;
			break;
		}
		slow = slow->next;
		fast = fast->next;
	}

	subhead = reverse(subhead);//恢复链表
	prev->next = subhead;
	return result;
}