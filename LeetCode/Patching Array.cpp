#include<vector>
//题目描述:给定一个已序正整数数组和一个值n，对数组添加元素，使得[1,n]之间的元素都可以被数组中的元素之和表示。
//        例如，[1,3]和6，添加2到数组中，那么[1,6]每个元素都可以被表示,[1], [2], [3], [1,3], [2,3], [1,2,3]
//解法描述:用一个miss变量表示目前能够表示的范围是[0, miss - 1],遍历数组，如果当前元素num[i] <= miss, 那么
//        当前能表示的范围就是[0, miss + nums[i]],因为miss之后的元素可以有miss + [0, miss - 1]之间的元素
//        表示，如果当前元素大于num[i]，那么这时需要加入一个元素，我们加入miss，然后miss值加倍，
int minPatches(std::vector<int>& nums, int n) 
{
	long miss = 1, res = 0, i = 0; //用long是为了防止溢出
	while (miss <= n)
	{
		if (i < nums.size() && nums[i] <= miss)
			miss += nums[i++];
		else
		{
			miss += miss;
			++res;
		}
	}
	return res;
}