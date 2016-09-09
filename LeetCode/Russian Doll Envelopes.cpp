#include<vector>
#include<algorithm>
//题目描述:给定一组pair，表示高度和宽度，如果一个pair的高度和宽度都比另一个pair的大，那么可以把另一个pair放
//        到这个pair里，求最多能放多少个
//解法描述:先排序，再动态规划，复杂度为n平方。可以通过二分查找优化成nlogn。

bool compare(const std::pair<int, int>&x , const std::pair<int, int>& y) 
{ //注意这里的排序方式
	return x.first != y.first ? x.first < y.first : x.second > y.second;
}

int maxEnvelopes(std::vector<std::pair<int, int>>& envelopes) 
{
	if (envelopes.empty())
		return 0;

	sort(envelopes.begin(), envelopes.end(), compare);

	std::vector<int> dp(envelopes.size()), height(envelopes.size() + 1, INT_MAX);
	for (int i = 0; i < envelopes.size(); ++i) 
	{
		int k = lower_bound(height.begin(), height.end(), envelopes[i].second) - height.begin();
		dp[i] = k;
		height[k] = envelopes[i].second;
	}

	int result = 0;
	for (int i = 0; i < envelopes.size(); ++i) 
		result = std::max(result, dp[i]);

	return result + 1;
}