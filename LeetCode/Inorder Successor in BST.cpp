#include"TreeNode.h"
//��Ŀ����:����һ��������������һ���ڵ㣬�ҵ�����ڵ�����������еĺ�̽ڵ�
//�ⷨ����:���p�������ӽڵ㣬��ô��̾���������������ߵĽڵ㣬���pû�����ӽڵ㣬����������������������ܵĺ�̵㣬root
//        ��ֵ��p�����������ߣ���ôroot�����Ǻ�̽ڵ㣬���root��p�����������ߣ������º�̽ڵ㣬��Ϊ�������Ǻ�̵�

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) 
{
	if (p->right)
	{
		TreeNode* node = p->right;
		while (node->left)
			node = node->left;
		return node;
	}

	TreeNode* successor = nullptr;
	while (root) 
	{
		if (p->val < root->val)//���������ߣ�root�����Ǻ�̽ڵ�
		{
			successor = root;
			root = root->left;
		}
		else if (p->val > root->val)//���������ߣ�����Ҫ���º�̽ڵ�
			root = root->right;
		else 
			break;
	}
	return successor;
}