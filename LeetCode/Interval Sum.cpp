#include<vector>
#include"TreeNode.h"
//题目描述:给定一个数组和一些query，每一个query代表一个区间，求出每个区间内的和
//解法描述:用一个sum数组，sum[i]表示从0到i的和，每一个区间的和等于某两个sum的差

std::vector<long long> intervalSum(std::vector<int>& A, std::vector<Interval> &queries) 
{
	std::vector<long long> vec;
	std::vector<long long> sum(A.size(), 0);
	sum[0] = A[0];
	for (int i = 1; i < A.size(); ++i)
		sum[i] = sum[i - 1] + A[i];

	for (int i = 0; i < queries.size(); ++i)
		vec.push_back(sum[queries[i].end] - sum[queries[i].start] + A[queries[i].start]);
	
	return vec;
}