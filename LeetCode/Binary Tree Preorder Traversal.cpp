#include<iostream>
#include<vector>
#include<stack>
#include"TreeNode.h"
//��Ŀ�������ȸ�����������
//�ⷨ����������ջ�������ڵ㣬Ȼ�������ע���Ȱ����ӽڵ�ѹ��ջ�У��ٰ����ӽڵ�ѹ��ջ�У���Ϊջ�Ǻ���ȳ���������һ��ѭ�����ȱ������ӽڵ�


std::vector<int> preorderTraversal(TreeNode *root) {
	std::vector<int> result;
	if (root == nullptr)
		return result;

	std::stack<TreeNode*> st;
	TreeNode* p = root;
	st.push(p);//�Ѹ��ڵ�ѹ��ջ��
	while (!st.empty())
	{
		p = st.top();//ȡ��ջ��Ԫ��
		st.pop();
		result.push_back(p->val);

		if (p->right != nullptr)//��ѹ�����ӽڵ�
			st.push(p->right);
		if (p->left != nullptr)
			st.push(p->left);
	}
	return result;
}