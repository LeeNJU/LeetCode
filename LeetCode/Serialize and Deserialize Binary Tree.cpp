#include "TreeNode.h"
#include<string>
#include<queue>
#include<vector>
class Codec 
{
public:
	std::string serialize(TreeNode* root) 
	{
		std::string s;

		std::queue<TreeNode*> q;
		q.push(root);
		while (!q.empty())
		{
			TreeNode* node = q.front();
			q.pop();
			if (node == nullptr)
				s += "nullptr,";
			else
			{
				s += root->val + '0' + ',';
				q.push(root->left);
				q.push(root->right);
			}
		}
		return s;
	}

	TreeNode* deserialize(std::string data)
	{
		std::vector<std::string> vec;
		for (int i = 0; i < data.size();)
		{
			int index = i;
			while (data[index] != ',')
				++index;
			vec.push_back(data.substr(i, index - i));
			i = index + 1;
		}


	}
};