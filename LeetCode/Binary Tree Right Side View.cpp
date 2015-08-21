#include"TreeNode.h"
#include<vector>
#include<queue>

//题目描述：给定一个二叉树，假设站在这颗树的右边，找到你能看到的元素，即求出树每一层的最右边的元素
//解法描述:层次遍历二叉树，用null作分隔符，用一个变量记录每一层的元素，当遇到null分隔符的时候，这个变量就是这一层的
//        最右边的元素

std::vector<int> rightSideView(TreeNode* root)
{
	std::vector<int> result;
	if (root == nullptr)
		return result;

	std::queue<TreeNode*> q;
	q.push(root);
	q.push(nullptr);//null为层与层之间的分隔符
	int value = 0;//value记录这一层最右边的元素
	while (!q.empty())
	{
		TreeNode* p = q.front();
		q.pop();
		if (p != nullptr)
		{
			value = p->val;
			if (p->left)//压入左子树和右子树
				q.push(p->left);
			if (p->right)
				q.push(p->right);
		}
		else
		{
			result.push_back(value);
			if (!q.empty())
				q.push(nullptr);//压入null作为层分隔符
		}
	}
	return result;
}