#include<vector>
#include"TreeNode.h"
//��Ŀ����:����һ�������һЩquery��ÿһ��query����һ�����䣬���ÿ�������ڵĺ�
//�ⷨ����:��һ��sum���飬sum[i]��ʾ��0��i�ĺͣ�ÿһ������ĺ͵���ĳ����sum�Ĳ�

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