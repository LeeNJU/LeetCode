#include"TreeNode.h"
//题目描述：给定一个链表，每相邻两个元素进行交换，例如1->2->3->4，变成2->1->4->3
//解法描述：每两个节点一次进行交换即可

ListNode *swapPairs(ListNode *head) 
{
	if (head == nullptr || head->next == nullptr)//排除只有一个元素和空的情况
		return head;

	ListNode* p = head;
	head = head->next;  //保存返回值  head指向原链表的第二个元素
	while (p != nullptr && p->next != nullptr)
	{
		ListNode* temp = p->next;
		p->next = temp->next;
		temp->next = p;

		ListNode* next = p->next;//保存p下一个元素
		if (p->next != nullptr && p->next->next != nullptr)//检查下两个元素的情况
			p->next = p->next->next;
		p = next;
	}
	return head;
}
