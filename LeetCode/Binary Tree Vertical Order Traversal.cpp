#include<vector>
#include<queue>
#include"TreeNode.h"
#include<unordered_map>
//题目描述:给定一个二叉树，求出它的垂直遍历，例如二叉树为[3,9,20,4,5,2,7]，那么垂直遍历为[[4],[9],[3, 5, 2],
//        [20],[7]]
//解法描述:根节点的col比左子节点的col大1，比右子节点的col小1，进行层次遍历，更新每个点的col，并且用map存储
//        每个col的节点
std::vector<std::vector<int>> verticalOrder(TreeNode* root) 
{
	std::unordered_map<int, std::vector<int>> mp;//存同一个col里面的节点
	std::queue<std::pair<TreeNode*, int>> q;
	std::vector<std::vector<int>> res;
	if (!root) 
		return res;
	
	q.push(std::make_pair(root, 0));
	while (!q.empty())
	{
		TreeNode* current = q.front().first;
		int index = q.front().second;
		q.pop();
		mp[index].push_back(current->val);
		if (current->left)//左子节点的col比当前根节点小1
			q.push(std::make_pair(current->left, index - 1));
		if (current->right)
			q.push(std::make_pair(current->right, index + 1));
	}
	
	for (auto m : mp)
		res.push_back(m.second);
	
	return res;
}