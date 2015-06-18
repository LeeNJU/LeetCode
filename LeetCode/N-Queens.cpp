#include<vector>
#include<string>

//题目描述：N皇后问题，把n个皇后放到n*n的棋盘上，使得行，列或对角线上不能相互攻击
//解法描述：递归，用row来控制递归深度，第一层递归到第n层，每一层递归中分别从每一列迭代，检查是否可以放置皇后

void dfs(int row, std::vector<int> &C, std::vector<std::vector<std::string> > &result, std::vector<int>& columns,
	std::vector<int>& principal_diagonals, std::vector<int>& counter_diagonals) 
{
	const int N = C.size();
	if (row == N) // 终止条件，也是收敛条件，意味着找到了一个可行解
	{ 
		std::vector<std::string> solution;
		for (int i = 0; i < N; ++i) 
		{
			std::string s(N, '.');
			for (int j = 0; j < N; ++j) 
			{
				if (j == C[i]) 
					s[j] = 'Q';
			}
			solution.push_back(s);
		}
		result.push_back(solution);
		return;
	}
	for (int j = 0; j < N; ++j) // 扩展状态，一列一列的试
	{ 
		const bool ok = columns[j] == 0 && principal_diagonals[row + j] == 0 && counter_diagonals[row - j + N] == 0;
		if (ok) // 剪枝：如果合法，继续递归  执行扩展动作
		{ 
			C[row] = j;
			columns[j] = principal_diagonals[row + j] = counter_diagonals[row - j + N] = 1; //同一条主对角线的下标为row + j
			dfs(row + 1, C, result, columns, principal_diagonals, counter_diagonals); //同一条副对角线下标为row - j + N
			// 撤销动作
			// C[row] = 0;
			columns[j] = principal_diagonals[row + j] =
				counter_diagonals[row - j + N] = 0;
		}
	}
}

std::vector<std::vector<std::string> > solveNQueens(int n)
{
	std::vector<int> columns = std::vector<int>(n, 0);  //column保存当前那些列被占用了，不能再放皇后了
	std::vector<int> principal_diagonals = std::vector<int>(2 * n, 0); //principal_diagonals保存占据了那些主对角线，左下到右上的为主对角线
	std::vector<int> counter_diagonals = std::vector<int>(2 * n, 0); //保存占据了哪些副对角线，左上到右下的为副对角线
	std::vector<std::vector<std::string> > result;
	std::vector<int> C(n, 0); // C[i] 表示第i 行皇后所在的列编号
	dfs(0, C, result, columns, principal_diagonals, counter_diagonals); //row为行数，用来控制递归的深度
	return result;
}
