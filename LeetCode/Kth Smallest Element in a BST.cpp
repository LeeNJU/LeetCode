#include"TreeNode.h"
#include<stack>

//题目描述：给定一个二叉树，找到其中第k小的元素
//解法描述：中序遍历

int kthSmallest(TreeNode* root, int k)
{
	std::stack<TreeNode*> s;
	TreeNode* p = root;
	int count = 0;
	while (!s.empty() || p != nullptr)
	{
		if (p != nullptr) //把从根节点开始一直到最左边的节点上的所有节点压入栈中
		{
			s.push(p);
			p = p->left;
		}
		else //当p为nullptr时，弹出栈顶元素，然后把右子树的左子节点全部压入栈中
		{
			p = s.top();
			s.pop();
			++count;
			if (count == k)
				return p->val;
			p = p->right;
		}
	}
}