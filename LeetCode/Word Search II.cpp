#include<vector>
#include<string>

bool existed(std::vector<std::vector<char>>& board, std::vector<std::vector<bool>>& visited, std::string word, int index, int i, int j)
{
	if (index == word.size())
		return true;
	if (visited[i][j])
		return false;
	if (word[index] != board[i][j])
		return false;

	visited[i][j] = true;
	bool done = false;
	if (!done && i + 1 < board.size())
		done = existed(board, visited, word, index + 1, i + 1, j);
	if (!done && j + 1 < board[0].size())
		done = existed(board, visited, word, index + 1, i, j + 1);
	if (!done && i - 1 >= 0)
		done = existed(board, visited, word, index + 1, i - 1, j);
	if (!done && j - 1 >= 0)
		done = existed(board, visited, word, index + 1, i, j - 1);
	return done;
}

std::vector<std::string> findWords(std::vector<std::vector<char>>& board, std::vector<std::string>& words) 
{
	std::vector<std::string> result;
	std::vector<std::vector<bool>> visited(board.size(), std::vector<bool>(board[0].size(), false));
	for (int i = 0; i < words.size(); ++i)
	{
		for (int j = 0; j < board.size(); ++j)
		{
			for (int k = 0; k < board[0].size(); ++k)
			{
				std::vector<std::vector<bool>> visited(board.size(), std::vector<bool>(board[0].size(),false));
				if (board[j][k] == words[i][0])
				{
					if (existed(board, visited, words[i], 0, j, k))
						result.push_back(words[i]);
				}
			}
		}
	}
	return result;
}