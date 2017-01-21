#include<vector>
#include<algorithm>
//题目描述:给定两个数组，每个数组只包含0到9的数字，代表两个数，给定值k，从两个数组中选出k个数字，使得它们组成的
//        数最大，每个数组中的数字的相对顺序保持不变。例如[3, 4, 6, 5]，[9, 1, 2, 5, 8, 3]， k = 5，组成的最大
//        数是[9, 8, 6, 5, 3]
//解法描述:从第一个数组中一次取出i个数字，第二个数组中取出k - i个数字，0 <= i <= k,遍历所有的情况，保存最大值


std::vector<int> maxVector(std::vector<int> nums, int k)//从数组中选出k个数字，使得组成的数字最大
{
	int drop = nums.size() - k;
	std::vector<int> result;
	for (int num : nums)
	{
		while (drop && result.size() && result.back() < num)
		{
			result.pop_back();
			--drop;
		}
		result.push_back(num);
	}

	result.resize(k);
	return result;
}

std::vector<int> mergeVector(std::vector<int> nums1, std::vector<int> nums2)
{                           //从两个数组中合并数字形成最大的数字，注意必须用vector进行比较，
	std::vector<int> result;//两个指针进行比较的方式有错，例如[6,0],  [6,7,9],当两个数字相等的时候，无法确认
	while (nums1.size() + nums2.size()) //应该移动哪个指针
	{
		std::vector<int>& tmp = nums1 > nums2 ? nums1 : nums2;
		result.push_back(tmp[0]);
		tmp.erase(tmp.begin());
	}
	return result;
}

std::vector<int> maxNumber(std::vector<int>& nums1, std::vector<int>& nums2, int k) 
{
	int m = nums1.size(), n = nums2.size();
	std::vector<int> result;
	for (int i = std::max(0, k - n); i <= std::min(k, m); ++i)//注意这里i的取值范围
	{  //遍历所有可能的k，取最大
		result = std::max(result, mergeVector(maxVector(nums1, i), maxVector(nums2, k - i)));
	}
	return result;
}