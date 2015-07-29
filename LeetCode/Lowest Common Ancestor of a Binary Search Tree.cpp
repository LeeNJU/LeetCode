#include"TreeNode.h"

//��Ŀ����������һ���������������ڵ㣬�ҵ��������ڵ����С���Ƚڵ�
//�ⷨ�������ݹ�

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
{
	if (root->val == p->val || root->val == q->val || (root->val < p->val && root->val > q->val) 
		|| (root->val < q->val && root->val > p->val)) //����һ��δ���ڵ�  ����p��q��root������
		return root;

	if (root->val > p->val && root->val > q->val) //�����ڵ㶼�ȸ��ڵ�С
		return lowestCommonAncestor(root->left, p, q);
	if (root->val < p->val && root->val < q->val) //�����ڵ㶼�ȸ��ڵ��
		return lowestCommonAncestor(root->right, p, q);
}