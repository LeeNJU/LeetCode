#include<vector>
#include"TreeNode.h"
//��Ŀ����������һ������������飬���������ת���ɸ߶�ƽ��Ķ�����
//�ⷨ������Ҫת���ɸ߶�ƽ��Ķ����������߾�����ƽ������˶�ÿһ�����飬ѡ�м�Ԫ����Ϊ���ڵ㣬����ֳ����������飬ÿ��������ݹ�ת����������ĸ��ڵ���Ϊ
//���ڵ�������ӽڵ�

TreeNode* build(int first, int last, const std::vector<int>& num)//first��lastΪ�����±�
{
	if (first > last)
		return nullptr;

	int middle = (first + last) / 2;//ѡ�м�Ԫ����Ϊ���ڵ�
	TreeNode* root = new TreeNode(num[middle]);

	root->left = build(first, middle - 1, num);//������������ݹ���ã�����������ĸ��ڵ㣬��Ϊ�����ӽڵ�
	root->right = build(middle + 1, last, num);

	return root;
}

TreeNode* sortedArrayToBST(std::vector<int>& num)
{
	return build(0, num.size() - 1, num);
}