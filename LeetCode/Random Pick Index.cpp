#include<vector>
//题目描述:给定一组数字，包含重复元素，给定数组中的一个元素，随机返回这个元素的任一一个下标，例如
//        {1,2,3,3,3},给定数字3，数字3的下标2,3或者4，返回任意一个下标，每个下标被选中的概率相同
//解法描述:reservoir sampling.扫描数组，用count记录target数字的个数，每当找到一个target数字，就取模，如果
//        结果为0，就赋值

class Solution 
{
private:
	std::vector<int> vec;
public:
	Solution(std::vector<int> nums) :vec(nums){}

	int pick(int target) 
	{
		int count = 0, result = -1;
		for (int i = 0; i < vec.size(); ++i) 
		{
			if (vec[i] == target)
			{
				++count;
				if (rand() % count == 0)//注意这里，这里保证每个index的概率相等
					result = i;
			}
		}
		return result;
	}
};