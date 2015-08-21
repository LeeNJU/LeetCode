#include<vector>
#include<stack>
#include"TreeNode.h"
//��Ŀ����������һ�������ж����Ƿ��Ƕ���������
//�ⷨ�������������
bool isValidBST(TreeNode* root)
{
	std::stack<TreeNode*> s;
	std::vector<int> inorder;
	TreeNode* node = root;
	while (node)//���ӽڵ�ѹ��ջ��
	{
		s.push(node);
		node = node->left;
	}

	while (!s.empty())//�������
	{
		node = s.top();
		s.pop();
		inorder.push_back(node->val);
		node = node->right;
		while (node)
		{
			s.push(node);
			node = node->left;
		}
	}

	for (int i = 1; i < inorder.size(); ++i)//����
	{
		if (inorder[i] <= inorder[i - 1])
			return false;
	}
	return true;
}