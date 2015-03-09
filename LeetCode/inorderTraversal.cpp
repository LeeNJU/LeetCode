#include<vector>
#include<stack>
#include"TreeNode.h"
//��Ŀ�������и�����������
//�ⷨ�������Ѹ��ڵ��Լ��������������ĸ��ڵ�ѹ��ջ�У�ֱ�����ӽڵ�Ϊ�գ�����ջ��Ԫ�أ�Ҳ����ĳһ�������ĸ��ڵ㣬ѹ���������ĸ��ڵ�
std::vector<int> inorderTraversal(TreeNode *root) {
	std::vector<int> result;
	const TreeNode *p = root;
	std::stack<const TreeNode *> s;
	while (!s.empty() || p != nullptr) {
		if (p != nullptr) {//�ѴӸ��ڵ㿪ʼһֱ������ߵĽڵ��ϵ����нڵ�ѹ��ջ��
			s.push(p);
			p = p->left;
		}
		else {
			p = s.top();
			s.pop();
			result.push_back(p->val);
			p = p->right;
		}
	}
	return result;
}