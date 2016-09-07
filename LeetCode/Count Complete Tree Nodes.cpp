#include"TreeNode.h"
#include<algorithm>
//��Ŀ����������һ�������������������һ��֮�⣬ÿһ�㶼�������˽ڵ㣩������ڵ�ĸ���
//�ⷨ����:������ȫֻ�õݹ飬Ч��̫�ͣ������ݹ��Ч�ʣ���Ը��ڵ㣬������ڵ㵽����������ײ�ĸ߶ȣ��жϸ߶�
//        �Ƿ���ȣ������ȣ�������������������ݹ����

int getLeftHeight(TreeNode* r)//������ĸ��ڵ㵽����ߵĸ߶�
{
	int height = 0;
	while (r)
	{
		++height;
		r = r->left;
	}
	return height;
}

int getRightHeight(TreeNode* r)
{
	int height = 0;
	while (r)
	{
		++height;
		r = r->right;
	}
	return height;
}

int countNodes(TreeNode* root)
{
	if (root == nullptr)
		return 0;

	int left = getLeftHeight(root);//ע�����ﴫ����root
	int right = getRightHeight(root);
	if (left == right)
		return pow(2, left) - 1;
	else
		return countNodes(root->left) + countNodes(root->right) + 1;
}