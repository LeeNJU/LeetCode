#include<vector>
#include<queue>
//题目描述:给定一个二维数组，只包含O或者X，找到所有被X包围的O，然后把这些O全部换成X，注意边界上的O不能被换成X
//解法描述:
void bfs(std::vector<std::vector<char>>& board, int i, int j)
{
	if (i < 0 || j > board[0].size())
		return;

	std::queue<int> q;
	q.push(i);
	q.push(j);
	while (!q.empty())
	{
		int row = q.front();
		q.pop();
		int col = q.front();
		q.pop();
		if (board[row][col] == '#')
			continue;

		board[row][col] = '#';
		if (row + 1 < board.size() && board[row + 1][col] == 'O')
		{
			q.push(row + 1);
			q.push(col);
		}
		if (col + 1 < board[0].size() && board[row][col + 1] == 'O')
		{
			q.push(row);
			q.push(col + 1);
		}
		if (row - 1 >= 0 && board[row - 1][col] == 'O')
		{
			q.push(row - 1);
			q.push(col);
		}
		if (row - 1 >= 0 && board[row][col - 1] == 'O')
		{
			q.push(row);
			q.push(col - 1);
		}
	}
}

void solve(std::vector<std::vector<char>>& board)
{
	if (board.empty() || board[0].empty())
		return;

	int n = board.size();
	int m = board[0].size();
	for (int i = 0; i < n; ++i)
	{
		if (board[i][0] == 'O')//第一列
			bfs(board, i, 0);
		if (board[i][m - 1] == 'O')//最后一列
			bfs(board, i, m - 1);
	}

	for (int i = 0; i < m; ++i)
	{
		if (board[0][i] == 'O')//第一行
			bfs(board, 0, i);
		if (board[n - 1][i] == 'O')//最后一行
			bfs(board, n - 1, i);
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (board[i][j] == 'O')
				board[i][j] = 'X';
			if (board[i][j] == '#')
				board[i][j] = 'O';
		}
	}
}}
}