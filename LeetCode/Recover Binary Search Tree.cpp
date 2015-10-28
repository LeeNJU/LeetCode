#include"TreeNode.h"
#include<vector>
//题目描述：给定一棵二叉树，其中有两个节点被交换了，找到这两个节点并恢复二叉树的结构
//解法描述：用morris中序遍历的方式进行中序遍历，一边遍历，一边检测是否符合二叉树结构，注意交换的节点可能是相邻的，也可能
//         不是相邻的

void detect(std::pair<TreeNode*, TreeNode*>& broken, TreeNode* prev, TreeNode* current) 
{
	if (prev != nullptr && prev->val > current->val) //如果prev的值比current的值大，说明找到一个节点
	{
		if (broken.first == nullptr) //有可能是相邻的节点被交换，有可能不是相邻的节点被交换
			broken.first = prev;
		broken.second = current;
	}
}

void recoverTree(TreeNode* root)
{
	std::pair<TreeNode*, TreeNode*> broken;
	TreeNode* prev = nullptr;
	TreeNode* cur = root;
	while (cur)  //morris中序遍历
	{
		if (cur->left == nullptr)
		{
			detect(broken, prev, cur);
			prev = cur;
			cur = cur->right;
		}
		else
		{
			TreeNode* temp = cur->left;
			while (temp->right != nullptr && temp->right != cur)
				temp = temp->right;

			if (temp->right == nullptr)
			{
				temp->right = cur;
				cur = cur->left;
			}
			else
			{
				detect(broken, prev, cur);
				prev = cur;
				temp->right = nullptr;
				cur = cur->right;
			}
		}
	}

	std::swap(broken.first->val, broken.second->val);
}