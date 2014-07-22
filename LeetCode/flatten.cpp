#include<iostream>
#include"TreeNode.h"

using namespace std;


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