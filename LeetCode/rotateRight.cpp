#include"TreeNode.h"
//��Ŀ����������һ����������������תkλ��1->2->3->4->5->NULL��ת2λ��4->5->1->2->3->NULL
//�ⷨ������ֱ�ӵ���������ע��k��ֵ���ܴܺ󣬵�k�������ȵı���ʱ������Ҫ��ת������k��Ҫ�Գ���ȡģ


ListNode* rotateRight(ListNode* head, int k)
{
	if (head == nullptr || k <= 0)
		return head;

	int length = 1;
	ListNode* last = head;
	while (last->next)//�������,lastָ�����һ��Ԫ�أ���������������
	{
		++length;
		last = last->next;
	}

	if (k % length == 0)//k�������ȵı�������ô���÷�ת����
		return head;

	k = length - k % length - 1;//�����Ҫ����ƶ��Ĳ���
	ListNode* p = head;
	while (k--)
		p = p->next;

	ListNode* result = p->next;//��������
	p->next = nullptr;
	last->next = head;
	return result;
}