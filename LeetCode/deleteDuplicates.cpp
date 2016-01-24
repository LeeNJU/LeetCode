#include"TreeNode.h"
#include<limits.h>
//题目描述：给定一个已序链表，删除其中的重复元素，使得每个元素只出现一次
//解法描述：两个指针prev和cur，当prev和cur的元素相等的时候，prev指向cur的下一个元素

ListNode *deleteDuplicates(ListNode *head) {
	if (head == nullptr)
		return nullptr;

	for (ListNode *prev = head, *cur = head->next; cur; cur = cur->next) {
		if (prev->val == cur->val) 
		{
			prev->next = cur->next;
			delete cur;
		}
		else 
			prev = cur;
	}
	return head;
}


//版本二：给定一个已序链表，如果有重复的元素，就把所有重复的元素删除，1->2->3->3->4->4->5，删除后为1->2->5
//解法描述：添加一个哨兵节点，两个指针prev和cur分别指向哨兵节点和头节点，2层循环，当cur遇到重复元素时，循环
//         删除重复元素

ListNode *deleteDuplicate(ListNode *head)
{
	if (head == nullptr)
		return nullptr;

	ListNode dummy(INT_MIN);
	dummy.next = head;
	ListNode* prev = &dummy, *cur = head;
	while (cur)
	{
		bool duplicated = false;
		while (cur->next != nullptr && cur->val == cur->next->val)
		{
			duplicated = true;
			ListNode* temp = cur;
			cur = cur->next;
			delete temp;
		}
		if(duplicated) // 删除重复的最后一个元素
		{ 
			ListNode *temp = cur;
			cur = cur->next;
			delete temp;
			continue;
		}
		prev->next = cur;
		prev = prev->next;
		cur = cur->next;	
	}

	prev->next = cur;
	return dummy.next;
}