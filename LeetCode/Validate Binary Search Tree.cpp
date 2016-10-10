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
		if (!inorder.empty() && node->val <= inorder[inorder.size() - 1]) //�ڱ��������н��м��
			return false;
		inorder.push_back(node->val);
		node = node->right;
		while (node)
		{
			s.push(node);
			node = node->left;
		}
	}
	return true;
}

//�ݹ�ⷨ:��ÿһ���ڵ㣬���뵱ǰ�ڵ��ȡֵ��Χ�������ֵ����Сֵ,���ڸտ�ʼ�ĸ��ڵ�lowȥlong����Сֵ��up
//        ȡlong�����ֵ
/*
bool dfs(TreeNode* root, long low, long up) 
{
	if (root == nullptr) 
		return true;

	if (root->val >= up || root->val <= low) 
		return false;

	return dfs(root->left, low, root->val) && dfs(root->right, root->val, up);
}*/