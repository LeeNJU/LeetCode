#include"TreeNode.h"

//题目描述：给定一个二叉树和两个节点，找到这两个节点的最小祖先节点
//解法描述：递归

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
{
	if (root->val == p->val || root->val == q->val || (root->val < p->val && root->val > q->val) 
		|| (root->val < q->val && root->val > p->val)) //其中一个未父节点  或者p和q在root的两边
		return root;

	if (root->val > p->val && root->val > q->val) //两个节点都比根节点小
		return lowestCommonAncestor(root->left, p, q);
	if (root->val < p->val && root->val < q->val) //两个节点都比根节点大
		return lowestCommonAncestor(root->right, p, q);
}