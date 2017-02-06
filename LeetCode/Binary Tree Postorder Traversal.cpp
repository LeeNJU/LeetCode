#include<vector>
#include<stack>
#include"TreeNode.h"

//题目描述：完成二叉树的后序遍历
//解法描述：用栈,用current表示当前访问的节点，last表示上一次访问的节点，访问当前节点时，如果当前节点是叶子节点，
//        那么直接输出，如果上一次访问的节点时当前节点的左子节点或者右子节点，那么也可以立即输出，

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
		{   //当前节点是叶子节点，或者上一次访问的节点是当前节点的左子节点或者右子节点
			result.push_back(current->val);
			stack.pop();//弹栈
			last = current;//更新last指针
		}
		else
		{
			if (current->right)//先放右子节点
				stack.push(current->right);
			if (current->left)//再放左子节点
				stack.push(current->left);
		}
	}
	return result;
}