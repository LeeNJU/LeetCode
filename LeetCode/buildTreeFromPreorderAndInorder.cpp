#include<algorithm>
#include<vector>
#include"TreeNode.h"
//��Ŀ����������һ���������������������������Ľ�������������������
//�ⷨ�������ݹ鹹�죬��������ĵ�һ��Ԫ�ؾ��Ǹ��ڵ㣬Ȼ���ҵ����ڵ������������λ�ã�ȷ��������


TreeNode* build(std::vector<int>::iterator prefirst, std::vector<int>::iterator prelast,
	std::vector<int>::iterator infirst, std::vector<int>::iterator inlast)
{
	if (prefirst >= prelast || infirst >= inlast)
		return nullptr;

	TreeNode* root = new TreeNode(*prefirst);//����ڵ�ĵ�һ��Ԫ��Ϊ���ڵ�
	std::vector<int>::iterator iter = find(infirst, inlast, root->val);//�ҵ����ڵ�����������е�λ��

	std::vector<int>::iterator first = prefirst;
	advance(first, distance(infirst, iter));//�ҵ��������ĳ��Ⱥ�����������е��±�
	root->left = build(++prefirst, ++first, infirst, iter);//�������ݹ����

	root->right = build(first, prelast, ++iter, inlast);//�������ݹ����

	return root;
}

TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder)
{
	return build(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
}

