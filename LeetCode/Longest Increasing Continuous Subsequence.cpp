#include<vector>
#include<algorithm>

//题目描述:给定一个数组，找到其中最长的连续递增或者连续递减的子数组，例如[5, 4, 2, 1, 3]最长的连续递增或者
//        递减的子数组是[5, 4, 2, 1],长度是4
//解法描述:扫描两边，先从左往右得到连续递减的子数组，然后从右往左得到连续递增的子数组。
int longestIncreasingContinuousSubsequence(std::vector<int>& A) 
{
	if (A.empty())
		return 0;

	int left_max = 1;
	int left_length = 1; //length为包含当前元素的长度，max为全局最大值
	for (int i = 1; i < A.size(); ++i)//从左往右得到连续递减的子数组
	{
		if (A[i] < A[i - 1])
		{
			++left_length;
			left_max = std::max(left_max, left_length);
		}
		else
			left_length = 1;
	}

	int right_max = 1;
	int right_length = 1;
	for (int i = A.size() - 2; i >= 0; --i)//从右往左得到连续递增的子数组
	{
		if (A[i] < A[i + 1])
		{
			++right_length;
			right_max = std::max(right_max, right_length);
		}
		else
			right_length = 1;
	}

	return std::max(left_max, right_max);
}