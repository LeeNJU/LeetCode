#include"TreeNode.h"
#include<queue>
#include<vector>
//题目描述:给定一个二叉树，找到最后一层的第一个元素，例如
//                    2
//                 1     3   最后一层的第一个元素是1
//解法描述:层次遍历，只需要记录每一层的第一个元素就行了

int findBottomLeftValue(TreeNode* root) 
{
	std::queue<TreeNode*> queue;
	queue.push(root);
	queue.push(nullptr);

	std::vector<int> vec;
	while (!queue.empty())
	{
		TreeNode* node = queue.front();
		queue.pop();

		if (node != nullptr)
		{
			if (vec.empty())//利用vec是否为空来判断是不是第一个元素
				vec.push_back(node->val);
			if (node->left)
				queue.push(node->left);
			if (node->right)
				queue.push(node->right);
		}
		else
		{
			if (!queue.empty())
			{
				vec.clear();
				queue.push(nullptr);
			}
		}
	}

	return vec.front();
}