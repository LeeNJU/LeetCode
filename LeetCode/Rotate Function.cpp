#include<vector>
#include<algorithm>
//题目描述:给定一个integer数组，求出最大的f操作的值，例如[4, 3, 2, 6]，那么
//        F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
//        F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
//        F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
//        F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26
//        其中最大的是F(3)，返回26
//解法描述:找规律，先求出所有元素的和，下一个f操作，会把最后一个元素放到最前面，系数会变成0，其他元素的系数
//        会加1，那么f(n + 1) = f(n) - 当前最后一个元素 * (n - 1) + 其他元素的和
int maxRotateFunction(std::vector<int>& A)
{
	if (A.empty())
		return 0;

	int n = A.size();
	int sum = 0, f = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += A[i];
		f += i * A[i];
	}

	int result = f;
	for (int i = n - 1; i > 0; --i)
	{
		f = f - (n - 1) * A[i] + sum - A[i];
		result = std::max(result, f);
	}

	return result;
}