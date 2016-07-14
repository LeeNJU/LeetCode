#include<vector>
#include<algorithm>
//题目描述:给定两个已序数组，要求找到和最小的k个组合，例如[1,1,2],[1,2,3],k = 10,返回
//        [[1,1],[1,1],[2,1],[1,2],[1,2],[2,2],[1,3],[1,3],[2,3]]
//解法描述:遍历所有可能组合，用最大堆保存k个最小的组合。不能使用双指针遍历，会漏掉合理的组合

//比较函数
bool compare(const std::pair<int, int> pair_one, const std::pair<int, int> pair_two)
{
	return pair_one.first + pair_one.second <= pair_two.first + pair_two.second;
}

std::vector<std::pair<int, int>> kSmallestPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k)
{
	std::vector<std::pair<int, int>> result;//最后的结果，也用来作为最大堆
	for (int i = 0; i < std::min((int) nums1.size(), k); ++i)//两层遍历
	{
		for (int j = 0; j < std::min((int) nums2.size(), k); ++j)
		{
			if (result.size() < k)//堆的大小不足k个
			{
				result.push_back(std::pair<int, int>(nums1[i], nums2[j]));
				push_heap(result.begin(), result.end(), compare);
			}
			else if (nums1[i] + nums2[j] < result[0].first + result[0].second)//当前组合比堆顶组合小
			{
				result.push_back(std::pair<int, int>(nums1[i], nums2[j]));
				push_heap(result.begin(), result.end(), compare);
				pop_heap(result.begin(), result.end(), compare);
				result.pop_back();
			}
		}
	}
	return result;
}