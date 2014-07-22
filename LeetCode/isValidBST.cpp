#include<stack>
#include<vector>
#include"TreeNode.h"
using namespace std;



bool isValidBST(TreeNode* root)
{
	if (root == nullptr)
		return true;

	if (root->left == nullptr && root->right == nullptr)
		return true;

	stack<TreeNode*> s;
	vector<int> result;
	TreeNode* p = root;

	while (p != nullptr)
	{
		s.push(p);
		p = p->left;
	}

	while (!s.empty())
	{
		TreeNode* q = s.top();
		s.pop();
		result.push_back(q->val);

		if (q->right != nullptr)
		{
			TreeNode* node = q->right;
			while (node != nullptr)
			{
				s.push(node);
				node = node->left;
			}
		}
	}

	for (size_t i = 0; i < result.size() - 1; i++)
	if (result[i] >= result[i + 1])
		return false;

	return true;

}