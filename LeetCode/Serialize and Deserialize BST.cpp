#include"TreeNode.h"
#include<string>
#include<stack>
//��Ŀ����:����һ�����������������л���һ���ַ�����Ȼ������ַ��������л���һ������������
//�ⷨ����:������������������л���Ȼ����verify preorder traversal��˼·�����л�

class Codec 
{
public:
	std::string serialize(TreeNode* root) 
	{
		if (root == nullptr)
			return "";

		std::string result = "";
		std::stack<TreeNode*> stack;
		stack.push(root);

		while (!stack.empty())//�������
		{
			TreeNode* node = stack.top();
			stack.pop();

			result += std::to_string(node->val) + " ";
			if (node->right)
				stack.push(node->right);
			if (node->left)
				stack.push(node->left);
		}
		return result;
	}

	TreeNode* deserialize(std::string data) 
	{
		if (data.empty())
			return nullptr;

		int index = 0;
		int pos = index;
		while (data[pos] != ' ')
			++pos;

		TreeNode* root = new TreeNode(stoi(data.substr(index, pos - index)));//�ҵ����ڵ�
		std::stack<TreeNode*> stack;
		stack.push(root);
		index = pos + 1;
		while (index < data.size())
		{
			int pos = index;
			while (data[pos] != ' ')
				++pos;

			TreeNode* node = new TreeNode(stoi(data.substr(index, pos - index)));//�ҵ���ǰ�ڵ�
			index = pos + 1;
			if (stack.empty())
				stack.push(node);
			else if (node->val < stack.top()->val)//��ǰԪ�ر�ջ��Ԫ��С��˵����ջ��Ԫ�ص����ӽڵ�
			{
				stack.top()->left = node;
				stack.push(node);
			}
			else //��ǰԪ�ر�ջ��Ԫ�ش�˵����ǰ�ڵ���ĳ���ڵ�����ӽڵ�
			{
				TreeNode* n = nullptr;
				while (!stack.empty() && stack.top()->val < node->val)//�ҵ����ڵ�
				{
					n = stack.top();
					stack.pop();
				}

				n->right = node;
				stack.push(node);
			}
		}

		return root;
	}
};