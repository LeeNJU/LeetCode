#include<vector>
#include<queue>
#include<algorithm>
#include"TreeNode.h"
//题目描述:给定一个二叉树，找到每一层的最大元素，例如
//                     1
//                 3        2
//            5        3        9
//         那么每一层的最大元素分别是[1,3,9]
//解法描述:层次遍历，保存每一层的最大元素

std::vector<int> largestValues(TreeNode* root)
{
	if (root == nullptr)
		return std::vector<int>();

	std::queue<TreeNode*> queue;
	queue.push(root);
	queue.push(nullptr);

	std::vector<int> result;
	int max_val = INT_MIN;
	while (!queue.empty())
	{
		TreeNode* node = queue.front();
		queue.pop();

		if (node)
		{
			max_val = std::max(max_val, node->val);
			if (node->left)
				queue.push(node->left);
			if (node->right)
				queue.push(node->right);
		}
		else
		{
			result.push_back(max_val);
			if (!queue.empty())
			{
				max_val = INT_MIN;
				queue.push(nullptr);
			}
		}
	}

	return result;