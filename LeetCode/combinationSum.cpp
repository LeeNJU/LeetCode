#include<vector>
#include<algorithm>
//题目描述：给定一个数组和一个值target，从数组中找到和为target的所有组合，其中每一个元素可以被使用无数次，例如{2,3,6,7}中找和为7的组合，答案为{7}，{2,2,3}
//解法：先对数组排序，再递归求解

std::vector<std::vector<int> > combinationSum(std::vector<int> &candidates, int target)
{
	sort(candidates.begin(), candidates.end());//先进行排序
	std::vector<std::vector<int>> result;
	std::vector<int> intermediate;
	dfs(result, intermediate, candidates, 0, target);
	return result;
}

void dfs(std::vector<std::vector<int>>& result, std::vector<int>& intermediate, std::vector<int> num, int index, int target)//index为开始的下标，target为寻找的值，该值逐渐减少
{
	if (target == 0)//target为0，表示已经找到一个合适的值
	{
		result.push_back(intermediate);
		return;
	}
	for (int i = index; i < num.size(); ++i)//从index开始循环遍历数组
	{
		if (num[i] > target)//判断数组最小的值是否比target大，如果大的话，直接返回，引文此时不可能存在合理解
			return;
		intermediate.push_back(num[i]);
		dfs(result, intermediate, num, i, target - num[i]);//递归调用，其中target要减去当前元素的值
		intermediate.pop_back();//弹出最后一个元素，表示之前选中的元素经过上一步的递归没有找到解
	}	
}