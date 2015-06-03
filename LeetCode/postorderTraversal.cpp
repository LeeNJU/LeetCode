#include<vector>
#include<stack>
#include"TreeNode.h"

//��Ŀ��������ɶ������ĺ������
//�ⷨ��������ջ

std::vector<int> postorderTraversal(TreeNode* root) 
{
	std::vector<int> result; //p�����ڷ��ʵĽ�㣬q���ոշ��ʹ��Ľ��
	TreeNode* p, *q;
	std::stack<TreeNode*> s;
	p = root;
	do {
		while (p != nullptr) // ��������
		{ 
			s.push(p);
			p = p->left;
		}
		q = nullptr;
		while (!s.empty()) 
		{
			p = s.top();
			s.pop();
			
			if (p->right == q) // �Һ��Ӳ����ڻ��ѱ����ʣ�����֮
			{
				result.push_back(p->val);
				q = p; /* ����շ��ʹ��Ľ��*/
			}
			else 
			{				
				s.push(p);//��ǰ��㲻�ܷ��ʣ���ڶ��ν�ջ
				p = p->right;// �ȴ���������
				break;
			}
		}
	} while (!s.empty());
	return result;
}