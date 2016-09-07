#include<vector>
#include<algorithm>
#include"TreeNode.h"
//��Ŀ����������һ���������ĺ���������������������ݴ˹��������������
//�ⷨ�������ݹ�

TreeNode* build(std::vector<int>::iterator infirst, std::vector<int>::iterator inlast,
	std::vector<int>::iterator postfirst, std::vector<int>::iterator postlast)
{
	if (infirst >= inlast || postfirst >= postlast)
		return nullptr;

	TreeNode* root = new TreeNode(*--postlast);//������������һ���ڵ���Ǹ��ڵ�
	++postlast;

	std::vector<int>::iterator iter = find(infirst, inlast, root->val);//�ҵ����ڵ�����������е�λ��
	std::vector<int>::iterator last = postfirst;
	advance(last, distance(infirst, iter));//�õ��������ķ�Χ

	root->left = build(infirst, iter, postfirst, last);//�ݹ鹹��������
	root->right = build(++iter, inlast, last, --postlast);//�ݹ鹹��������
	return root;
}

TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder)
{
	return build(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
}