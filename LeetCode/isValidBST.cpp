#include<vector>
#include"TreeNode.h"
//题目描述：给定一个树，判断其是否是二叉树
//解法描述：递归传入两个参数，一个是左界，一个是右界，节点的值必须在两个界的中间，同时在判断做子树和右子树时更新左右界。
//bugs  此方法行不通  最好是中序
bool isValidBST(TreeNode* root, int lower, int upper)//注意必须是long，因为当root的值为INT_MAX时为出错
{
	if (root == nullptr)
		return true;
		
	if (root->val <= lower || root->val >= upper)
		return false;

	return root->val > lower && root->val < upper && isValidBST(root->left, lower, root->val) && isValidBST(root->right, root->val, upper);
}

bool isValidBST(TreeNode* root)
{
	return isValidBST(root, INT_MIN, INT_MAX);
}