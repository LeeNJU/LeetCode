#include"TreeNode.h"
//��Ŀ����������һ����������ת���ɸ߶�ƽ��Ķ���������
//�ⷨ�������ÿ���ָ���ҵ�������м䣬�Ͽ��������м�ڵ�Ϊ���ڵ㣬Ȼ��ݹ���Ұ벿���ҵ������ڵ㣬����벿���ҵ���
//         �ӽڵ�

TreeNode *sortedListToBST(ListNode *head) 
{
	if (head == nullptr || head->next == nullptr)
		return head == nullptr ? nullptr : new TreeNode(head->val);

	ListNode dummy(0);
	dummy.next = head;
	ListNode* slow = head, *fast = head, *prev = &dummy;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		prev = prev->next;
	}

	prev->next = nullptr; //ע������Ҫ�Ͽ�
	TreeNode* root = new TreeNode(slow->val);
	root->right = sortedListToBST(slow->next);
	root->left = sortedListToBST(head);
	return root;
}