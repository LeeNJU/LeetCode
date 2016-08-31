#include<vector>
#include<unordered_map>

//题目描述：给定一个数组，其长度为n，找到其中出现次数大于n/2的元素，假设数组非空，并且一定存在这样的元素
//解法描述：用candidate表示最后的结果，count表示candidate出现的次数，遍历数组，如果count等于0，那么candidate
//         为nums[i]，count加1，如果count不等于0并且candidate等于nums[i]，那么count加1，如果candidate不等
//         于nums[i]，就把count减1，如果candidate不是最后要找的元素，那么一定会碰到足够多的其他元素使得这个
//         candidate的count为0，如果candidate就是最后要找的元素，那么candidate的count会减少，但不会等于0

int majorityElement(std::vector<int>& nums)
{
	int candidate = 0, count = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (count == 0)
		{
			candidate = nums[i];
			++count;
		}
		else
		{
			if (candidate == nums[i])
				++count;
			else
				--count;
		}
	}
	return candidate;
}

//题目描述:找到数组中出现次数大于n / 3的元素
//解法描述:最多有两个元素出现的次数大于n / 3，解法类似上一题
std::vector<int> majorityElement2(std::vector<int>& nums) 
{
	std::vector<int> result;

	int count1 = 0, count2 = 0, candidate1 = 0, candidate2 = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] == candidate1) //注意这里必须先判断当前元素是不是与两个candidate元素相等
			++count1;
		else if (nums[i] == candidate2)
			++count2;
		else if (count1 == 0)
		{
			++count1;
			candidate1 = nums[i];
		}
		else if (count2 == 0)
		{
			++count2;
			candidate2 = nums[i];
		}
		else
		{
			--count1;
			--count2;
		}
	}

	count1 = 0;
	count2 = 0;
	for (int i = 0; i < nums.size(); ++i) //验证两个candidate元素的出现次数的确大于n / 3
	{
		if (nums[i] == candidate1)
			++count1;
		else if (nums[i] == candidate2)
			++count2;
	}

	if (count1 > nums.size() / 3)
		result.push_back(candidate1);
	if (count2 > nums.size() / 3)
		result.push_back(candidate2);
	return result;
}

//题目描述：给定一个数组和一个值k，找到数组中出现次数大于n/k的元素
//解法描述：用hashtable记录每个元素出现的次数

int majorityNumber(std::vector<int> nums, int k)
{
	std::unordered_map<int, int> m;
	int count = nums.size() / k;
	for (int i = 0; i < nums.size(); ++i)
	{
		++m[nums[i]];
		if (m[nums[i]] > count)
			return nums[i];
	}
}