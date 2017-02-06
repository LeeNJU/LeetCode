#include<vector>
#include<stack>
#include"TreeNode.h"

//��Ŀ��������ɶ������ĺ������
//�ⷨ��������ջ,��current��ʾ��ǰ���ʵĽڵ㣬last��ʾ��һ�η��ʵĽڵ㣬���ʵ�ǰ�ڵ�ʱ�������ǰ�ڵ���Ҷ�ӽڵ㣬
//        ��ôֱ������������һ�η��ʵĽڵ�ʱ��ǰ�ڵ�����ӽڵ�������ӽڵ㣬��ôҲ�������������

std::vector<int> postorderTraversal(TreeNode* root) 
{
	std::vector<int> result;
	if (root == nullptr)
		return result;
	std::stack<TreeNode*> stack;

	TreeNode* current = nullptr, *last = nullptr;
	stack.push(root);

	while (!stack.empty())
	{
		current = stack.top();
		if ((current->left == nullptr && current->right == nullptr) ||
			((last != nullptr) && (current->left == last || current->right == last)))
		{   //��ǰ�ڵ���Ҷ�ӽڵ㣬������һ�η��ʵĽڵ��ǵ�ǰ�ڵ�����ӽڵ�������ӽڵ�
			result.push_back(current->val);
			stack.pop();//��ջ
			last = current;//����lastָ��
		}
		else
		{
			if (current->right)//�ȷ����ӽڵ�
				stack.push(current->right);
			if (current->left)//�ٷ����ӽڵ�
				stack.push(current->left);
		}
	}
	return result;
}