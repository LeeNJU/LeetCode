#include"TreeNode.h"
#include<string>
#include<stack>
//题目描述:给定一个二叉搜索树，序列化成一个字符串，然后根据字符串反序列化成一个二叉搜索树
//解法描述:利用先序遍历进行序列化，然后按照verify preorder traversal的思路反序列化

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

		while (!stack.empty())//先序遍历
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

		TreeNode* root = new TreeNode(stoi(data.substr(index, pos - index)));//找到根节点
		std::stack<TreeNode*> stack;
		stack.push(root);
		index = pos + 1;
		while (index < data.size())
		{
			int pos = index;
			while (data[pos] != ' ')
				++pos;

			TreeNode* node = new TreeNode(stoi(data.substr(index, pos - index)));//找到当前节点
			index = pos + 1;
			if (stack.empty())
				stack.push(node);
			else if (node->val < stack.top()->val)//当前元素比栈顶元素小，说明是栈顶元素的左子节点
			{
				stack.top()->left = node;
				stack.push(node);
			}
			else //当前元素比栈顶元素大，说明当前节点是某个节点的右子节点
			{
				TreeNode* n = nullptr;
				while (!stack.empty() && stack.top()->val < node->val)//找到父节点
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