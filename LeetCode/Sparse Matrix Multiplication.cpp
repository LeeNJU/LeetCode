#include<vector>
//题目描述:给定两个稀疏矩阵，求他们的乘积
//解法描述:扫描A矩阵的每个元素，如果该元素不是0，A[i][j] != 0,那么该元素所在的i行可以和B矩阵的每一列相乘，
//         也就是说，A[i][j]元素可以和B[j][k]相乘，其结果最终会加到C[i][k]元素中。

std::vector<std::vector<int>> multiply(std::vector<std::vector<int>>& A, std::vector<std::vector<int>>& B)
{
	int m = A.size();
	int n = B.size();
	int p = B[0].size();
	std::vector<std::vector<int>> C(m, std::vector<int>(p, 0));//C矩阵初始化成0

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (A[i][j])//不是0，表示A[i][j]可以和每一个B[j][k]相乘
			{
				for (int k = 0; k < p; ++k)
					C[i][k] += A[i][j] * B[j][k];
			}
		}
	}
	return C;
}