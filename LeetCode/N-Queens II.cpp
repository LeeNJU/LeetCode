#include<vector>

//题目描述：N皇后问题，求出解的个数
//解法描述：与上一次类似

void dfs(int row, std::vector<int> &C, std::vector<int>& columns, std::vector<int>& principal_diagonals, std::vector<int>& counter_diagonals, int& count) 
{
	const int N = C.size();
	if (row == N) // 终止条件，也是收敛条件，意味着找到了一个可行解
	{ 
		++count;
		return;
	}
	for (int j = 0; j < N; ++j) // 扩展状态，一列一列的试
	{ 
		const bool ok = columns[j] == 0 && principal_diagonals[row + j] == 0 && counter_diagonals[row - j + N] == 0;
		if (ok) // 剪枝：如果合法，继续递归 执行扩展动作
		{ 
			C[row] = j;
			columns[j] = principal_diagonals[row + j] = counter_diagonals[row - j + N] = 1;
			dfs(row + 1, C, columns, principal_diagonals, counter_diagonals, count);
			// 撤销动作
			// C[row] = 0;
			columns[j] = principal_diagonals[row + j] = counter_diagonals[row - j + N] = 0;
		}
	}
}

int totalNQueens(int n)
{
	int count = 0;
	std::vector<int> columns = std::vector<int>(n, 0);
	std::vector<int> principal_diagonals = std::vector<int>(2 * n, 0);
	std::vector<int> counter_diagonals = std::vector<int>(2 * n, 0);
	std::vector<int> C(n, 0); // C[i] 表示第i 行皇后所在的列编号
	dfs(0, C, columns, principal_diagonals, counter_diagonals, count);
	return count;
}