#include"TreeNode.h"

//��Ŀ����������һ�������ж����Ƿ���Palindrome
//�ⷨ��������������м�Ͽ����ֳ����룬�Ѻ�һ������ת��Ȼ�����αȽ�

ListNode* reverse(ListNode* head) //��ת����
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

bool isPalindrome(ListNode* head) {
	if (head == nullptr || head->next == nullptr)
		return true;

	ListNode* slow = head, *fast = head;
	ListNode dummy(0);
	dummy.next = head;
	ListNode* prev = &dummy;
	while (fast && fast->next)//����ָ��Ͽ�����
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

	subhead = reverse(subhead);//�ָ�����
	prev->next = subhead;
	return result;
}