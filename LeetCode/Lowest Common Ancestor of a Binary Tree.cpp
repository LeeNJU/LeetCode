#include"TreeNode.h"
//题目描述:给定一个二叉树和两个节点，找到这两个节点的最低的公共父节点
//解法描述:递归，注意，如果左子树递归返回的结果不是nullptr，那么并不代表该结果就是最终的结果，因为左子树包含
//        p或者q中的一个节点的时候，也会返回非nullptr，这时候要看右子树的递归结果
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
{
	if (!root || root == p || root == q)
		return root;

	TreeNode* left = lowestCommonAncestor(root->left, p, q);
	TreeNode* right = lowestCommonAncestor(root->right, p, q);
	return !left ? right : !right ? left : root;
}