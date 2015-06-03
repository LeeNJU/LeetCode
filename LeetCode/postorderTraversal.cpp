#include<vector>
#include<stack>
#include"TreeNode.h"

//题目描述：完成二叉树的后序遍历
//解法描述：用栈

std::vector<int> postorderTraversal(TreeNode* root) 
{
	std::vector<int> result; //p，正在访问的结点，q，刚刚访问过的结点
	TreeNode* p, *q;
	std::stack<TreeNode*> s;
	p = root;
	do {
		while (p != nullptr) // 往左下走
		{ 
			s.push(p);
			p = p->left;
		}
		q = nullptr;
		while (!s.empty()) 
		{
			p = s.top();
			s.pop();
			
			if (p->right == q) // 右孩子不存在或已被访问，访问之
			{
				result.push_back(p->val);
				q = p; /* 保存刚访问过的结点*/
			}
			else 
			{				
				s.push(p);//当前结点不能访问，需第二次进栈
				p = p->right;// 先处理右子树
				break;
			}
		}
	} while (!s.empty());
	return result;
}