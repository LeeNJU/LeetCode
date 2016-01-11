#include"TreeNode.h"
//��Ŀ����:����һ����������ÿ���ڵ�Ҫôû�����ӽڵ㣬Ҫô�����ӽڵ�����ӽڵ㣬�������ӽڵ���Ҷ�ӽڵ�,���ڶ�
//        �ö��������з�ת��ʹ��ԭ�������ӽڵ�����Ҷ�ӽڵ㣬����:
//            1                 4
//          2    3  ����>       5    2
//        4   5                  3    1
//�ⷨ����:����ÿ���ڵ㣬�ֵܽڵ������ӽڵ㣬���ڵ������ӽڵ㣬�����õݹ�
TreeNode *upsideDownBinaryTree(TreeNode *root)
{
	TreeNode* parent = nullptr;//������һ���ĸ��׽ڵ���ֵܽڵ�
	TreeNode* right = nullptr;
	while (root)
	{
		TreeNode* left = root->left;
		root->left = right;
		right = root->right;
		root->right = parent;
		parent = root;
		root = left;
	}
	return parent;
}