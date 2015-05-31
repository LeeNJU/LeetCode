#include<vector>
#include<unordered_map>

//题目描述:给定一个数组，判断其中是否包含重复元素
//解法描述：用hashtable
bool containsDuplicate(std::vector<int>& nums) {
	std::unordered_map<int, int> m;
	for (int i = 0; i < nums.size(); ++i)
	{
		++m[nums[i]];
		if (m[nums[i]] > 1)
			return true;
	}
	return false;
}