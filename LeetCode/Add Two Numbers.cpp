#include"TreeNode.h"
#include<stack>
//��Ŀ�������������������ֱ��ʾ����������������������
//�ⷨ��������addBinary

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) 
{
	ListNode head(-1);
	int carry = 0;
	ListNode* prev = &head;
	for (ListNode* pa = l1, *pb = l2; pa != nullptr || pb != nullptr; pa = pa == nullptr ? nullptr : pa->next, pb = pb == nullptr ? nullptr : pb->next, prev = prev->next)
	{
		const int ai = pa == nullptr ? 0 : pa->val;
		const int bi = pb == nullptr ? 0 : pb->val;
		const int value = (ai + bi + carry) % 10;
		carry = (ai + bi + carry) / 10;
		prev->next = new ListNode(value);//β�巨
	}
	if (carry > 0)  //����������п��ܽ�λ
		prev->next = new ListNode(carry);
	return head.next;
}

//�������������ʾ�����Ǹ����֣�����ߵ�λ��ʾ���λ�����������ֵĺͣ�����(7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
//��ʾ7243 + 564 = 7807������7 -> 8 -> 0 -> 7
//�ⷨ����:��ջ�����������֣�Ȼ�����

ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) 
{
	std::stack<int> s1, s2;

	while (l1) //�ŵ�ջ��
	{
		s1.push(l1->val);
		l1 = l1->next;
	}

	while (l2) 
	{
		s2.push(l2->val);
		l2 = l2->next;
	}

	int sum = 0;
	ListNode dummy(0);
	while (!s1.empty() || !s2.empty())
	{
		if (!s1.empty())
		{
			sum += s1.top();
			s1.pop();
		}

		if (!s2.empty())
		{
			sum += s2.top();
			s2.pop();
		}
		
		ListNode* node = new ListNode(sum % 10);
		node->next = dummy.next;
		dummy.next = node;
		sum /= 10;
	}

	if (sum != 0)
	{
		ListNode* node = new ListNode(1);
		node->next = dummy.next;
		dummy.next = node;
	}

	return dummy.next;
}