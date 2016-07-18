#include"TreeNode.h"

//题目描述：反转单链表
//解法描述：用一个哨兵节点，依次把第二，三，四等个节点放到哨兵节点后面，1->2->3->4->5->6, 2->1->3->4->5->6, 3->2->1->4->5->6,....

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