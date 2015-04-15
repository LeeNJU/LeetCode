#include"TreeNode.h"
//��Ŀ����������һ������ÿ���ڵ㶼����һ��randomeָ�룬ָ�������е�ĳһ��Ԫ�ػ���Ϊnull��������ɸ���������
//�ⷨ����������һ���µĽڵ㣬�ͰѸýڵ���뵽��Ӧԭ�ڵ�ĺ��棬����һ����randomeָ���ֵ����������ֿ���2����������ԭ����Ϊ1->2, �����Ϊ1->1->2->2,Ȼ���ڷֿ�

RandomListNode *copyRandomList(RandomListNode *head) 
{
	if (head == nullptr)
		return nullptr;

	for (RandomListNode* cur = head; cur != nullptr;)//�����µĽڵ㣬���µĽڵ���뵽��Ӧԭ�ڵ�ĺ���
	{
		RandomListNode* node = new RandomListNode(cur->label);
		node->next = cur->next;
		cur->next = node;
		cur = node->next;
	}

	for (RandomListNode* cur = head; cur != nullptr;)//����ÿ���ڵ��randomָ��
	{
		if (cur->random != nullptr)
			cur->next->random = cur->random->next;//ע����cur->randome->next
		cur = cur->next->next;
	}

	RandomListNode new_head(-1);
	for (RandomListNode* cur = head, *new_node = &new_head; cur != nullptr;)//�ָ���������
	{
		new_node->next = cur->next;
		new_node = new_node->next;
		cur->next = cur->next->next;
		cur = cur->next;
	}

	return new_head.next;
}