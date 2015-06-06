#include"TreeNode.h"

//��Ŀ����������һ�������һ��ֵk��ÿk���ڵ����һ�η�ת������1->2->3->4->5��k=3������3->2->1->4->5
//�ⷨ��������һ���ڱ��ڵ㣬ÿk��Ԫ�ؽ��з�ת

ListNode* reverse(ListNode* prev, ListNode* first, ListNode* last) //first��last֮���Ԫ����Ҫ��ת�����ط�ת������һ���ڵ�ָ��
{
	ListNode* start = first;// ���淴ת�����һ���ڵ��ָ��
	while (first != last)//��ת�������ΰ�first��last�����Ԫ�ؽ��з�ת��last�����ƶ�
	{
		prev->next = first->next;
		ListNode* p = last->next;
		first->next = p;
		last->next = first;
		first = prev->next;
	}
	return start;
}

ListNode* reverseKGroup(ListNode* head, int k)
{
	if (head == nullptr || head->next == nullptr || k < 2) //�ų��������
		return head;

	ListNode dummy(-1);
	dummy.next = head;
	for (ListNode *prev = &dummy, *end = head; end; end = prev->next) 
	{
		for (int i = 1; i < k && end; ++i) //endָ������ƶ�k-1λ
			end = end->next;
		if (end == nullptr) // ����k ��
			break; 
		prev = reverse(prev, prev->next, end); //prev��prev->next��end����Ϊnull
	}
	return dummy.next;
}