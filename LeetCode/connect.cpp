#include"TreeNode.h"
//题目描述：给定一个二叉树，每一个节点都增加一个指针，该指针指向同一层的相邻节点（即同一层的相邻的右边那个节点），如果相邻节点不存在，指针设为null
//解法描述：递归，构造另一个递归函数，增加一个参数sibling，表示该节点的兄弟节点

void connects(TreeLinkNode* root, TreeLinkNode* sibling)//sibling表示root的兄弟节点，刚开始时，sibling为null，因为root没有兄弟节点
{
	if (root == nullptr)//设置root的next指针
		return;
	else
		root->next = sibling;

	connects(root->left, root->right);//递归设置左子树
	if (sibling)//当sibling不为空的时候，右子节点的兄弟节点为sibling的左子节点，这里要注意
		connects(root->right, sibling->left);
	else//sibling为空，右子节点的next指针也为空
		connects(root->right, nullptr);
}

void connect(TreeLinkNode* root)
{
	connects(root, nullptr);
}

//变种
//题目描述：上一题的二叉树是满二叉树，现在要求变为任意的二叉树
//解法描述：递归求解，从每一层的最左边的节点开始，遍历同一层的节点，设置同一层的节点的next指针，然后递归调用设置下一层，dummy节点用来记录每一层
//最左边的节点
void connect2(TreeLinkNode* root)
{
	if (root == nullptr) 
		return;

	TreeLinkNode dummy(-1);//dummy节点的下一个节点是每一层的最左边的节点
	for (TreeLinkNode *curr = root, *prev = &dummy; curr; curr = curr->next)//遍历同一层的节点，设置节点的next指针 
	{
		if (curr->left != nullptr)
		{
			prev->next = curr->left;
			prev = prev->next;
		}
		if (curr->right != nullptr)
		{
			prev->next = curr->right;
			prev = prev->next;
		}
	}
	connect(dummy.next);//递归调用
}