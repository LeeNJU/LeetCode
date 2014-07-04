#include<iostream>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) { }
};

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