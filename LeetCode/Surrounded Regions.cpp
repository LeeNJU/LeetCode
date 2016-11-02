#include<vector>
#include<queue>
//��Ŀ����:����һ����ά���飬ֻ����O����X���ҵ����б�X��Χ��O��Ȼ�����ЩOȫ������X��ע��߽��ϵ�O���ܱ�����X
//�ⷨ����:�ӱ߽��ϵ�O��ʼ���й��ѻ������ѣ����ܹ��ѵ���Oȫ������#����ôʣ�µ�O��Ȼ��X��Χ��Ȼ��ɨ���������飬
//        ��O����X,Ȼ���#����O
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

			board[x][y] = '#';//ע������ѵ���Ϊvisited
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
		if (board[i][0] == 'O')//��һ��
			bfs(board, i, 0);
		if (board[i][m - 1] == 'O')//���һ��
			bfs(board, i, m - 1);
	}

	for (int i = 0; i < m; ++i)
	{
		if (board[0][i] == 'O')//��һ��
			bfs(board, 0, i);
		if (board[n - 1][i] == 'O')//���һ��
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
