#include"TreeNode.h"
//��Ŀ����:����һ���������������ڵ㣬�ҵ��������ڵ����͵Ĺ������ڵ�
//�ⷨ����:�ݹ飬ע�⣬����������ݹ鷵�صĽ������nullptr����ô��������ý���������յĽ������Ϊ����������
//        p����q�е�һ���ڵ��ʱ��Ҳ�᷵�ط�nullptr����ʱ��Ҫ���������ĵݹ���
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
{
	if (!root || root == p || root == q)
		return root;

	TreeNode* left = lowestCommonAncestor(root->left, p, q);
	TreeNode* right = lowestCommonAncestor(root->right, p, q);
	return !left ? right : !right ? left : root;
}