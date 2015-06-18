#include<vector>
#include<algorithm>

//题目描述：给定一个整数数组（包含重复元素），返回这些数字所有的组合
//解法描述：递归，先排序，遇到重复元素就跳过，非重复元素就把它放到当前序列的第一位，把该元素加入到perm中，然后递归，递归完了要排序

void dfs(std::vector<int>& nums, int index, std::vector<int> &perm, std::vector<std::vector<int> > &result)
{
	int size = nums.size();
	if (size == index)  //找到一个解
		result.push_back(perm);
	else 
	{
		for (int i = index; i < size; ++i) //从index开始迭代 
		{
			if ((i > index) && (nums[i] == nums[index])) //有重复元素，跳过
				continue;
			else 
				std::swap(nums[index], nums[i]); //不是重复元素，i和index交换，把当前元素放到第一位
			perm.push_back(nums[index]);
			dfs(nums, index + 1, perm, result);
			perm.pop_back();
		}
		sort(nums.begin() + index, nums.end()); //前面可能nums的顺序，进行恢复
	}
}

std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums)
{
	std::vector<std::vector<int> > result;
	std::vector<int> perm;
    std::sort(nums.begin(), nums.end());  //先进行排序，方便去重
	dfs(nums, 0, perm, result);
    return result;
}