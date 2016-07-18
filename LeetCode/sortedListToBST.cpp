#include"TreeNode.h"
//题目描述：给定一个链表，把它转换成高度平衡的二叉搜索树
//解法描述：用快慢指针找到链表的中间，断开链表，以中间节点为根节点，然后递归从右半部分找到右做节点，从左半部分找到左
//         子节点

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

	prev->next = nullptr; //注意这里要断开
	TreeNode* root = new TreeNode(slow->val);
	root->right = sortedListToBST(slow->next);
	root->left = sortedListToBST(head);
	return root;
}