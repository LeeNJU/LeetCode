#include<vector>
#include<stack>
#include"TreeNode.h"
//题目描述：中根遍历二叉树
//解法描述：把根节点以及其所有左子树的根节点压入栈中，直到左子节点为空，弹出栈顶元素，也就是某一个子树的根节点，压入右子树的根节点
std::vector<int> inorderTraversal(TreeNode *root) {
	std::vector<int> result;
	const TreeNode *p = root;
	std::stack<const TreeNode *> s;
	while (!s.empty() || p != nullptr) 
	{
		if (p != nullptr) //把从根节点开始一直到最左边的节点上的所有节点压入栈中
		{
			s.push(p);
			p = p->left;
		}
		else 
		{
			p = s.top();
			s.pop();
			result.push_back(p->val);
			p = p->right;
		}
	}
	return result;
}