#include"TreeNode.h"
//��Ŀ����������һ���������������ƽ����һ�������������ӽڵ����ӵ����ڵ����ָ���ϣ����ӽڵ����ӵ����ӽڵ����ָ����
//�ⷨ�������ݹ飬�ȱ�ƽ����������Ȼ���ƽ��������

void flatten(TreeNode* root)//�Ѷ�������ƽ��
{
	if (root == nullptr)
		return;

	TreeNode* rightSubtree = root->right;//��¼������
	root->right = root->left;//�������Ƶ��ҽڵ�
	root->left = nullptr;
	flatten(root->right);//flatten������

	TreeNode* p = root;
	while (p->right != nullptr)
	{
		p = p->right;
	}
	p->right = rightSubtree;
	flatten(rightSubtree);//flatten������
}