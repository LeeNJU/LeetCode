#include"TreeNode.h"
#include<algorithm>
//题目描述:给定一个二叉树，找到最大的路径和，其中起始点可以是任意节点，终止节点也可以是任意节点。但是必须满足
//         parent-child关系
//解法描述:最优解可能存在于某个树的子树(局部解)，所以用result引用。 对于任意一个节点，有4种情况，左子树的路径，右子树
//         的路径，节点本身，以及左子树的路径 + 节点本身 + 右子树的路径
int findMax(TreeNode* root, int& result)
{
	if (root == nullptr)
		return 0;

	int left_sub = findMax(root->left, result); //求以左子节点为根的路径之和
	int right_sub = findMax(root->right, result); //求以右子节点为根的路径之和
	int max_sum = std::max(std::max(left_sub, right_sub) + root->val, root->val); //比较求出最大值
	result = std::max(std::max(root->val + left_sub + right_sub, max_sum), result);
	return  max_sum; //注意这里，返回的是左路径之和，右路径之和，当前节点之间的最大值，不包括左路径 + 右路径 + 当前
	                 //节点
}
int maxPathSum(TreeNode* root) 
{
	int result = INT_MIN;
	findMax(root, result);
	return result;

}