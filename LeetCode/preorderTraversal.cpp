#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

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