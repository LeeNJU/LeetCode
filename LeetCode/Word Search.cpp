#include<vector>
#include<string>

//��Ŀ����:����һ����ά�ַ������һ���ַ�����������������ҵ�һ��·����ʹ��·���ϵ��ַ��պ���ɸ������ַ�����
//         ֻ�ܴ�ֱ��ˮƽѰ��
//�ⷨ����:�����������ͬ����С�ľ�֤visited��������Ԫ���Ƿ��Ѿ������ʹ���

bool dfs(int x, int y, std::vector<std::vector<char>>& board, const std::string& word, int index, std::vector<std::vector<bool>>& visited)
{
	if (index == word.size())
		return true;

	if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size()) //Խ��
		return false;
	if (visited[x][y]) //��ǰԪ���Ѿ����ʹ���
		return false;
	if (board[x][y] != word[index]) //��ǰԪ�ز�����Ҫ�ҵ�Ԫ��
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
