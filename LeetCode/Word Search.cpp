#include<vector>
#include<string>

//题目描述:给定一个二维字符矩阵和一个字符串，从这个矩阵中找到一条路径，使得路径上的字符刚好组成给定的字符串，
//         只能垂直或水平寻找
//解法描述:深度搜索，用同样大小的举证visited表明各个元素是否已经被访问过了

bool dfs(int x, int y, std::vector<std::vector<char>>& board, const std::string& word, int index, std::vector<std::vector<bool>>& visited)
{
	if (index == word.size())
		return true;

	if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size()) //越界
		return false;
	if (visited[x][y]) //当前元素已经访问过了
		return false;
	if (board[x][y] != word[index]) //当前元素不等于要找的元素
		return false;

	visited[x][y] = true;
	bool result = dfs(x + 1, y, board, word, index + 1, visited) || dfs(x, y + 1, board, word, index + 1, visited)
		|| dfs(x - 1, y, board, word, index + 1, visited) || dfs(x, y - 1, board, word, index + 1, visited);
	visited[x][y] = false;
	return result;
}

bool exist(std::vector<std::vector<char>>& board, std::string word)
{
	int m = board.size();
	int n = board[0].size();
	std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (dfs(i, j, board, word, 0, visited))
				return true;
		}
	}
	return false;
}
