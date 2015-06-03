#include<vector>
#include<queue>
#include"TreeNode.h"

//题目描述：层次遍历二叉树，返回一个二维数组
//解法描述：用队列层次遍历，队列中加入nullptr作为层与层之间的分隔符

std::vector<std::vector<int>> levelOrder(TreeNode* root)
{
	std::vector<std::vector<int>> result;
	if (!root)
		return result;

	std::queue<TreeNode*> q;
	std::vector<int> level;
	q.push(root);
	q.push(nullptr);//nullptr作为层与层之间的分隔符

	while (!q.empty())
	{
		TreeNode* node = q.front();
		q.pop();
		if (node)//当前不是分隔符是节点
		{
			level.push_back(node->val);
			if (node->left)//加入左右节点
				q.push(node->left);
			if (node->right)
				q.push(node->right);
		}
		else//分隔符
		{
			result.push_back(level);
			level.clear();//清空level
			if (!q.empty())//注意，在q不为空的情况下才能加入nullptr分隔符
				q.push(nullptr);
		}
	}
	return result;
}