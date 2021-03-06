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
//解法描述：从每一层的最左边的节点开始，遍历同一层的节点，设置同一层的节点的next指针，然后循环设置下一
//         层，dummy节点用来记录每一层最左边的节点
void connect2(TreeLinkNode* root)
{
	if (!root)
		return;

	TreeLinkNode dummy(0);
	TreeLinkNode* prev = &dummy;
	TreeLinkNode* cur = root;
	while (cur)//遍历数的每一层
	{
		while (cur)//遍历树的某一层
		{
			if (cur->left)
			{
				prev->next = cur->left;
				prev = prev->next;
			}
			if (cur->right)
			{
				prev->next = cur->right;
				prev = prev->next;
			}
			cur = cur->next;
		}

		cur = dummy.next;//上一层遍历完之后，说明下一层的next指针都已经设置好了，开始遍历下一层
		dummy.next = nullptr;
		prev = &dummy;
	}
}