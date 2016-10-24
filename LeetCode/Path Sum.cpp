#include"TreeNode.h"
//题目描述:给定一棵二叉树和一个值，判断这课树是否有一条路径，使得这条路径上的数字之和等于给定的值
//解法描述:递归


bool hasPathSum(TreeNode* root, int sum)
{
	if (root == nullptr)
		return false;

	if (root->left == nullptr && root->right == nullptr)
		return sum == root->val;
	
	return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}

//题目描述：给定一棵二叉树和一个值，找出所有路径，使得路径上的数字之和等于给定的值
//解法描述：递归

void dfs(TreeNode* root, int sum, std::vector<std::vector<int>>& result, std::vector<int> temp)
{
	if (root == nullptr)
		return;

	temp.push_back(root->val);//记录路径上的节点
	if (root->left == nullptr && root->right == nullptr)//叶子节点
	{
		if (root->val == sum)
			result.push_back(temp);
		return;
	}

	dfs(root->left, sum - root->val, result, temp);//左节点递归
	dfs(root->right, sum - root->val, result, temp);//右节点递归
}

//题目描述:给定一个二叉树，找到和等于某个值的路径的个数，路径不一定要从root开始，也不一定要到叶子节点结束，
//        但是必须是从父节点到子节点的路径

int pathSumRec(TreeNode* root, int sum) //以root为起点，找到和为sum的路径个数
{
	if (root == nullptr)
		return 0;

	int rootmatch = (root->val == sum);
	int left = pathSumRec(root->left, sum - root->val);
	int right = pathSumRec(root->right, sum - root->val);

	return rootmatch + left + right;
}

int pathSum(TreeNode* root, int sum) 
{
	if (root == nullptr)
		return 0;

	int rootval = pathSumRec(root, sum);
	int lefttree = pathSum(root->left, sum);
	int righttree = pathSum(root->right, sum);
	return (rootval + lefttree + righttree);
}