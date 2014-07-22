#include<iostream>
#include<vector>
#include<stack>
#include"TreeNode.h"
using namespace std;


vector<int> preorderTraversal(TreeNode *root) {
	vector<int> result;
	if (root == NULL)
		return result;

	stack<TreeNode*> st;
	TreeNode* p = root;
	while (p != NULL || !st.empty())
	{
		if (p != NULL)
		{
			st.push(p);
			result.push_back(p->val);
			p = p->left;
		}
		else
		{
			p = st.top();
			st.pop();
			p = p->right;
		}
	}
	return result;
}