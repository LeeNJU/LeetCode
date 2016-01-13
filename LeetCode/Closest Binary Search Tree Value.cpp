#include"TreeNode.h"
#include<stack>

//��Ŀ����:����һ��������������һ��targetֵ���������ҵ���target��ӽ���ֵ
//�ⷨ����:����������
int closestValue(TreeNode* root, double target) 
{
	int closest = root->val;
	while (root) 
	{
		if (abs(closest - target) >= abs(root->val - target))
			closest = root->val;
		root = target < root->val ? root->left : root->right;
	}
	return closest;
}

//version 2 
//��Ŀ����:����һ��������������һ��targetֵ���������ҵ�k����target��ӽ���ֵ
//�ⷨ����:������ջ�ֱ��ҵ�target������ǰ���ͺ�̣�Ȼ��õ�k����ӽ��ĵ�

void predecessor(TreeNode* root, double target, std::stack<int>& s) 
{
	if (!root) 
		return;

	predecessor(root->left, target, s);
	if (root->val > target)
		return;
	s.push(root->val);
	s.push(root->val);
}

void sucessor(TreeNode* root, double target, std::stack<int>& s)
{
	if (!root)
		return;

	sucessor(root->left, target, s);
	if (root->val < target)
		return;
	s.push(root->val);
	sucessor(root->right, target, s);
}

std::vector<int> closestKValues(TreeNode* root, double target, int k) 
{
	std::vector<int> closest(k);
	std::stack<int> pre, suc;
	predecessor(root, target, pre);//�ҵ�target������ǰ���ڵ�
	predecessor(root, target, suc);//�ҵ�target�����к�̽ڵ�
	for (int i = 0; i < k; i++) 
	{
		if (pre.empty())
		{
			closest[i] = suc.top();
			suc.pop();
		}
		else if (suc.empty())
		{
			closest[i] = pre.top();
			pre.pop();
		}
		else if (abs(target - pre.top()) < abs(target - suc.top()))
		{
			closest[i] = pre.top();
			pre.pop();
		}
		else
		{
			closest[i] = suc.top();
			suc.pop();
		}
	}
	return closest;
}