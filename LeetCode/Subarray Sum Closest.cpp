#include<vector>
#include<algorithm>
//题目描述:给定一个数组，要求找到一个区间，使得这个区间的和的绝对值最接近0
//解法描述:f[i]表示数组从0到i的和，那么最优解必然是某两个f[i]和f[j]的差，构造pair，first代表从0到i的和，second代表下标，
//        对pair数组排序，最优解必然存在于两个相邻的数中
std::vector<int> subarraySumClosest(std::vector<int> nums)
{
	std::vector<int> vec(2, 0);
	std::vector<std::pair<int, int>> f(nums.size(), std::make_pair(0, 0));
	f[0].first = nums[0];
	f[0].second = 0;

	for (int i = 1; i < nums.size(); ++i) //first代表从0到i的和，second代表下标
	{
		f[i].first = f[i - 1].first + nums[i];
		f[i].second = i;
	}

	sort(f.begin(), f.end());//排序

	int diff = f[0].first;
	for (int i = 1; i < f.size(); ++i)
	{
		if (abs(f[i].first - f[i - 1].first) < abs(diff))
		{
			diff = f[i].first - f[i - 1].first;
			vec[0] = std::min(f[i - 1].second, f[i].second) + 1; //注意这里，排序之后，下标不一定按照大小顺序
			vec[1] = std::max(f[i].second, f[i - 1].second);
		}
	}
	return vec;
}