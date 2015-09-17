#include<vector>
#include<string>

bool existed(std::vector<std::vector<bool>> visited, const std::vector<std::vector<char>>& board, std::string& word, int index, int i, int j)
{
	if (index == word.size())
		return true;
	if (visited[i][j])
		return false;

	visited[i][j] = true;
	if (word[index] != board[i][j])
		return false;

	bool exist = false;
	if (!exist && (i + 1) < board.size())
		exist = existed(visited, board, word, index + 1, i + 1, j);
	if (!exist && (i - 1) >= 0)
		exist = existed(visited, board, word, index + 1, i - 1, j);
	if (!exist && (j + 1) < board[0].size())
		exist = existed(visited, board, word, index + 1, i, j + 1);
	if (!exist && (j - 1) >= 0)
		exist = existed(visited, board, word, index + 1, i, j - 1);
	return exist;

}

std::vector<std::string> findWords(std::vector<std::vector<char>>& board, std::vector<std::string>& words) 
{
	std::vector<std::string> result;
	std::vector<std::vector<bool>> visited(board.size(), std::vector<bool>(board[0].size(), false));
	for (int i = 0; i < words.size(); ++i)
	{
		if (existed(visited, board, words[i], 0, 0, 0))
			result.push_back(words[i]);
	}
	return result;
}