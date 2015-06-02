#include<vector>
//题目描述：给定一个sudoku，判断其是否是合格的sudoku，在每一行和每一列中，数字1-9只能出现一次，在3*3的格子中，数字1-9也只能出现一次
//解法描述：逐一检查

bool checkUsed(std::vector<bool>& used, char c)//判断当前字符是否已经出现过
{
	if (c == '.')
		return false;
	else if (used[c - '1'])
		return true;
	else
	{
		used[c - '1'] = true;
		return false;
	}
}

bool isValidSudoku(std::vector<std::vector<char>>& board)
{
	std::vector<bool> used(9, false);
	for (int i = 0; i < 9; ++i)
	{
		std::fill(used.begin(), used.end(), false);
		for (int j = 0; j < 9; ++j)//检查行是否满足要求
		{
			if (checkUsed(used, board[i][j]))
				return false;
		}

		std::fill(used.begin(), used.end(), false);
		for (int j = 0; j < 9; ++j)//检查列是否符合要求
		{
			if (checkUsed(used, board[j][i]))
				return false;
		}
	}

	for (int row = 0; row < 3; ++row)//检查9个小格子
	{
		for (int col = 0; col < 3; ++col)
		{
			std::fill(used.begin(), used.end(), false);
			for (int i = col * 3; i < col * 3 + 3; ++i)//检查一个格子
			{
				for (int j = row * 3; j < row * 3 + 3; ++j)
				{
					if (checkUsed(used, board[i][j]))
						return false;
				}
			}
		}
	}

	return true;
}