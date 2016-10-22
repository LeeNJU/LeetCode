#include<vector>
#include<algorithm>
//题目描述:给定一个数组，找到第三大的元素，例如[1, 5, 11, 5]，第三大的元素是1，如果第三大的元素不存在，返回
//        最大元素
//解法描述:遍历数组，依次保存第一大，第二大和第三大的元素
int thirdMax(std::vector<int>& nums) 
{
	long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;//注意这里要用LONG_MIN,因为可能含有INT_MIN
	for (int val : nums)
	{
		if (first < val)
		{
			third = std::max(third, second);
			second = std::max(second, first);
			first = val;
		}
		else if (second < val && val < first)
		{
			third = std::max(third, second);
			second = val;
		}
		else if (third < val && val < second)
			third = val;
	}

	return third == LONG_MIN ? first : third;
}