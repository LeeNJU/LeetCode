#include<vector>
//题目描述:给定一个数组，找到一个区间，使得区间里的和最大
//解法描述:局部解和全局最优解，保存局部最优解的sum和区间，然后更新全局最优解的区间
std::vector<int> continuousSubarraySum(std::vector<int>& A) 
{
	std::vector<int> result(2, 0);//result保存全局最优解的区间
	if (A.empty())
		return result;

	int local_sum = A[0], local_left = 0, local_right = 0;//保存局部最优解的sum和区间
	int global_sum = A[0];
	for (int i = 1; i < A.size(); ++i)
	{
		if (local_sum + A[i] <= A[i])//更新局部最优解的sum和区间
		{
			local_sum = A[i];
			local_left = i;
			local_right = i;
		}
		else
		{
			local_sum += A[i];
			local_right = i;
		}

		if (local_sum >= global_sum)//更新全局最优解的区间
		{
			global_sum = local_sum;
			result[0] = local_left;
			result[1] = local_right;
		}

	}
	return result;
}