#include<vector>

//题目描述：给定搞一个9*9矩阵，给出sudoku解
//解法描述：一个一个去试，然后检验是不是合格的解

bool isValid(const std::vector<std::vector<char>>& board, int x, int y) //检查当前坐标x，y是否是合格的，即在行，列以及小方格里是否出现重复数字
{
	int i, j;
	for (i = 0; i < 9; i++) // 检查y 列
	{
		if (i != x && board[i][y] == board[x][y]) //在其他行的同一个列上出现相同数字
			return false;
	}
	
	for (j = 0; j < 9; j++) // 检查x 行
	{
		if (j != y && board[x][j] == board[x][y])
			return false;
	}

	for (i = 3 * (x / 3); i < 3 * (x / 3 + 1); i++)
	{
		for (j = 3 * (y / 3); j < 3 * (y / 3 + 1); j++)
		{
			if (i != x && j != y && board[i][j] == board[x][y])
				return false;
		}
		
	}
	
	return true;
}

bool solve(std::vector<std::vector<char>>& board)
{
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			if (board[i][j] == '.')  //遍历整个board，碰到空格，就把1到9逐个去试
			{
				for (int k = 0; k < 9; ++k)
				{
					board[i][j] = '1' + k;
					if (isValid(board, i, j) && solve(board)) //递归求解
						return true;
					board[i][j] = '.';
				}
				return false;
			}
		}
	}
	
	return true;
}

void solveSudoku(std::vector<std::vector<char>>& board)
{
	solve(board);
}