#include"TreeNode.h"
//题目描述：给定一个链表，每个节点都包含一个randome指针，指向链表中的某一个元素或者为null，现在完成该链表的深
//         拷贝
//解法描述：构建一个新的节点，就把该节点插入到对应原节点的后面，再逐一复制randome指针的值，最后把链表分开成2
//         个链表，例如原链表为1->2, 插入后为1->1->2->2,然后在分开

RandomListNode *copyRandomList(RandomListNode *head) 
{
	if (head == nullptr)
		return nullptr;

	for (RandomListNode* cur = head; cur != nullptr;)//创建新的节点，把新的节点插入到对应原节点的后面
	{
		RandomListNode* node = new RandomListNode(cur->label);
		node->next = cur->next;
		cur->next = node;
		cur = node->next;
	}

	for (RandomListNode* cur = head; cur != nullptr;)//复制每个节点的random指针
	{
		if (cur->random != nullptr)
			cur->next->random = cur->random->next;//注意是cur->randome->next
		cur = cur->next->next;
	}

	RandomListNode new_head(-1);
	for (RandomListNode* cur = head, *new_node = &new_head; cur != nullptr;)//分割两个链表
	{
		new_node->next = cur->next;
		new_node = new_node->next;
		cur->next = cur->next->next;
		cur = cur->next;
	}

	return new_head.next;
}