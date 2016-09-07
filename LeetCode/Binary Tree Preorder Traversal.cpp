#include<iostream>
#include<vector>
#include<stack>
#include"TreeNode.h"
//题目描述：先根遍历二叉树
//解法描述：先用栈保留根节点，然后遍历，注意先把右子节点压入栈中，再把左子节点压入栈中，因为栈是后进先出，这样下一个循环就先遍历左子节点


std::vector<int> preorderTraversal(TreeNode *root) {
	std::vector<int> result;
	if (root == nullptr)
		return result;

	std::stack<TreeNode*> st;
	TreeNode* p = root;
	st.push(p);//把根节点压入栈中
	while (!st.empty())
	{
		p = st.top();//取出栈顶元素
		st.pop();
		result.push_back(p->val);

		if (p->right != nullptr)//先压入右子节点
			st.push(p->right);
		if (p->left != nullptr)
			st.push(p->left);
	}
	return result;
}