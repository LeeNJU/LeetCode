#include"TreeNode.h"
//题目描述:给定一个链表，把序数为奇数的节点连在一起，序数为偶数的节点连在一起，最后奇数在前，偶数在后
//解法描述:用两个哨兵节点分别代表奇数节点和偶数节点
ListNode* oddEvenList(ListNode* head) 
{
	ListNode even_dummy(0);
	ListNode odd_dummy(0);
	ListNode* even = &even_dummy;
	ListNode* odd = &odd_dummy;

	int count = 0;
	while (head)
	{
		++count;
		if (count % 2 == 1)
		{
			odd->next = head;
			odd = odd->next;
		}
		else
		{
			even->next = head;
			even = even->next;
		}

		head = head->next;
	}

	even->next = nullptr;
	odd->next = even_dummy.next;
	return odd_dummy.next;
}