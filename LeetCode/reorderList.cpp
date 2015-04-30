#include"TreeNode.h"
//��Ŀ����������һ������������в�����L0->L1->L2->L3...->Ln,ת����L0->Ln->L1->Ln-1...
//�ⷨ�������ҵ�������м䣬�ֳ���������������һ��������ת��Ȼ���ٺϲ�����������

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

	ListNode* slow = head, *fast = head, *prev = head;//һ����ָ�룬һ����ָ��
	while (fast && fast->next)
	{
		prev = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	prev->next = nullptr;//�ֳ����Σ�ǰһ�������ĩβ��Ϊnull��slowָ���������ͷ

	slow = reverse(slow);//��ת��������

	ListNode* cur = head;
	while (cur->next)//�ϲ���������,ע��ѭ����������
	{
		ListNode* temp = cur->next;
		cur->next = slow;
		slow = slow->next;
		cur->next->next = temp;
		cur = temp;
	}
	cur->next = slow;
}