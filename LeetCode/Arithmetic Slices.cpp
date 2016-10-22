#include<vector>
//题目描述:给定一个整数数组，一个序列是arithmetic，如果这个序列至少包含3个元素，并且相邻两个元素的差值相等，
//        例如，1, 3, 5, 7, 9是arithmetic，1, 1, 2, 5, 7不是arithmetic，要求找出数组中有多少个arithmetic
//        序列
//解法描述:动态规划，对于第i个元素，判断前三个元素组成的序列是不是arithmetic的，如果是，cur加1，之前cur保存的
//        是以第i-1个元素为终点的arithmetic序列的个数，如果A[i] - A[i - 1] == A[i - 1] - A[i - 2],说明第i
//        个元素可以和之前的元素组成更长的序列

int numberOfArithmeticSlices(std::vector<int>& A) 
{
	int cur = 0, sum = 0;
	for (int i = 2; i < A.size(); ++i)
	{
		if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) 
		{
			cur += 1;
			sum += cur;
		}
		else 
			cur = 0;
	}
	return sum;
}