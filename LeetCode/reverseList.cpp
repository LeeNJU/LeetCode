#include"TreeNode.h"

//��Ŀ��������ת������
//�ⷨ��������һ���ڱ��ڵ㣬���ΰѵڶ��������ĵȸ��ڵ�ŵ��ڱ��ڵ���棬1->2->3->4->5->6, 2->1->3->4->5->6, 3->2->1->4->5->6,....

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