#include"TreeNode.h"
#include<stack>

//题目描述：实现一个二叉搜索树的迭代器，有两个操作，next和hasNext，这两个操作的平均复杂度为O(1),空间复杂度为O(h),其中
//         next函数是指求出以当前节点为根节点的二叉搜索树中最小的元素，即最左边的节点
//解法描述：用一个栈来保存当前节点的所有左子结点，调用next弹出一个节点的时候，如果该节点的右子节点不为空，把右子树的
//         左子结点压入栈中
class BSTIterator 
{
private:
	std::stack<TreeNode*> s; //栈s用来保存当前节点的左子结点
public:
	BSTIterator(TreeNode *root) 
	{
		TreeNode* cur = root;  //所有左子结点压入栈中
		if (cur)
		{
			s.push(cur);
			while (cur->left)
			{
				s.push(cur->left);
				cur = cur->left;
			}
		}
	}

	/** @return whether we have a next smallest number */
	bool hasNext() 
	{
		return !s.empty();
	}

	/** @return the next smallest number */
	int next() 
	{
		TreeNode* top = s.top();
		s.pop();
		int result = top->val;
		top = top->right;
		while (top) //右子树的左子节点压入栈中
		{
			s.push(top);
			top = top->left;
		}
		return result;
	}
};