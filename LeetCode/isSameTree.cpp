#include"TreeNode.h"
//��Ŀ�����������������������ж����������Ƿ����
//�ⷨ�������ݹ�



bool isSameTree(TreeNode* p, TreeNode* q)
{
	if (p == nullptr && q == nullptr)//ͬʱΪnull
		return true;

	if (p == nullptr || q == nullptr)//����һ��Ϊnull������ͬʱΪnull
		return false;
	else if (p->val != q->val)
		return false;
	else
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);//������������������ͬʱ��ȣ�������&&

}
