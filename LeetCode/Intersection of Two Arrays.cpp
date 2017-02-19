#include<vector>
#include<algorithm>
#include<set>
//题目描述:给定两个数组，找出两个数组之间的公共元素，返回的结果中不能有重复元素。
//解法描述:数组排序，然后用双指针

std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) 
{
	sort(nums1.begin(), nums1.end());
	sort(nums2.begin(), nums2.end());

	int i = 0, j = 0;
	std::set<int> set;
	while (i < nums1.size() && j < nums2.size())
	{
		if (nums1[i] < nums2[j])
			++i;
		else if (nums1[i] > nums2[j])
			++j;
		else
		{
			set.insert(nums1[i]);
			++i;
			++j;
		}
	}

	return std::vector<int>(set.begin(), set.end());
}

//version2:允许结果中有重复元素，即元素出现了几次，应该在结果中反映出来
std::vector<int> intersection2(std::vector<int>& nums1, std::vector<int>& nums2)
{
	sort(nums1.begin(), nums1.end());
	sort(nums2.begin(), nums2.end());

	int i = 0, j = 0;
	std::vector<int> result;
	while (i < nums1.size() && j < nums2.size())
	{
		if (nums1[i] < nums2[j])
			++i;
		else if (nums1[i] > nums2[j])
			++j;
		else
		{
			result.push_back(nums1[i]);
			++i;
			++j;
		}
	}
	return result;
}