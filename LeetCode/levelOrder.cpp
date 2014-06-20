#include<iostream>
#include<queue>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

vector<vector<int> > levelOrder(TreeNode* root)
{
	if (root == NULL)
		return vector<vector<int> >();

	vector<vector<int> > result;
	vector<pair<TreeNode*, int> > vec;
	queue<pair<TreeNode*, int> > q;
	TreeNode* p = root;
	q.push(pair<TreeNode*, int>(root, 1));

	while (!q.empty())
	{
		pair<TreeNode*, int> node = q.front();
		q.pop();
		vec.push_back(node);
		if (node.first->left != NULL)
			q.push(pair<TreeNode*, int>(node.first->left, node.second + 1));
		if (node.first->right != NULL)
			q.push(pair<TreeNode*, int>(node.first->right, node.second + 1));
	}

	vector<int> v;
	v.push_back(vec[0].first->val);
	int level = vec[0].second;
	for (size_t i = 1; i < vec.size(); ++i)
	{
		if (vec[i].second > level)
		{
			++level;
			result.push_back(v);
			v.clear();
			v.push_back(vec[i].first->val);
		}
		else
		{
			v.push_back(vec[i].first->val);
		}
	}
	result.push_back(v);
	return result;
}