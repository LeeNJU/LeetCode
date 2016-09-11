#include<vector>
#include<stack>
#include"TreeNode.h"
//题目描述：给定一个树，判断其是否是二叉搜索树
//解法描述：中序遍历
bool isValidBST(TreeNode* root)
{
	std::stack<TreeNode*> s;
	std::vector<int> inorder;
	TreeNode* node = root;
	while (node)//左子节点压入栈中
	{
		s.push(node);
		node = node->left;
	}

	while (!s.empty())//中序遍历
	{
		node = s.top();
		s.pop();
		if (!inorder.empty() && node->val <= inorder[inorder.size() - 1]) //在遍历过程中进行检查
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