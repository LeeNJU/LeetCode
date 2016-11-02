#include<vector>
#include<queue>
//题目描述:给定一个二维数组，只包含O或者X，找到所有被X包围的O，然后把这些O全部换成X，注意边界上的O不能被换成X
//解法描述:从边界上的O开始进行广搜或者深搜，把能够搜到的O全部换成#，那么剩下的O必然被X包围，然后扫描整个数组，
//        把O换成X,然后把#换成O
void bfs(std::vector<std::vector<char>>& board, int i, int j)
{
	if (i < 0 || j > board[0].size())
		return;

	std::vector<int> dx = { 1, -1, 0, 0 };
	std::vector<int> dy = { 0, 0, 1, -1 };

	board[i][j] = '#';
	std::queue<int> q;
	q.push(i);
	q.push(j);
	while (!q.empty())
	{
		int row = q.front();
		q.pop();
		int col = q.front();
		q.pop();

		for (int i = 0; i < dx.size(); ++i)
		{
			int x = row + dx[i];
			int y = col + dy[i];
			if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || board[x][y] == '#'
				|| board[x][y] == 'X')
				continue;

			board[x][y] = '#';//注意这里，把点标记为visited
			q.push(x);
			q.push(y);
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
}
