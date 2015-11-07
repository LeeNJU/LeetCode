#include<vector>
//题目描述:给定一个图，判断这个图是不是一个树
//解法描述:一个图是不是一个树，首先没有环，并且保证每个点都是相连的。用union-find来做。对每一条边进行union
int findRoot(const std::vector<int>& nums, int i) //找到根节点
{
	while (nums[i] != i) 
		i = nums[i];
	return i;
}

bool validTree(int n, std::vector<std::pair<int, int>>& edges) 
{
	std::vector<int> nums(n, 0);
	for (int i = 0; i < n; i++) //对union进行初始化
		nums[i] = i;
	
	for (int i = 0; i < edges.size(); ++i)
	{
		int r1 = findRoot(nums, edges[i].first);//找根节点
		int r2 = findRoot(nums, edges[i].second);

		if (r1 == r2) //根节点相等，说明有环
			return false;

		nums[r1] = r2;//设置根节点
	}

	return edges.size() == n - 1;//最后判断边数是不是等于n-1
}