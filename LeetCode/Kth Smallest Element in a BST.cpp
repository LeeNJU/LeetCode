#include"TreeNode.h"
#include<stack>

//��Ŀ����������һ�����������ҵ����е�kС��Ԫ��
//�ⷨ�������������

int kthSmallest(TreeNode* root, int k)
{
	std::stack<TreeNode*> s;
	TreeNode* p = root;
	int count = 0;
	while (!s.empty() || p != nullptr)
	{
		if (p != nullptr) //�ѴӸ��ڵ㿪ʼһֱ������ߵĽڵ��ϵ����нڵ�ѹ��ջ��
		{
			s.push(p);
			p = p->left;
		}
		else //��pΪnullptrʱ������ջ��Ԫ�أ�Ȼ��������������ӽڵ�ȫ��ѹ��ջ��
		{
			p = s.top();
			s.pop();
			++count;
			if (count == k)
				return p->val;
			p = p->right;
		}
	}
}