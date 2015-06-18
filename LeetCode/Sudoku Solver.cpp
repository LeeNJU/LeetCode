#include<vector>

//��Ŀ������������һ��9*9���󣬸���sudoku��
//�ⷨ������һ��һ��ȥ�ԣ�Ȼ������ǲ��Ǻϸ�Ľ�

bool isValid(const std::vector<std::vector<char>>& board, int x, int y) //��鵱ǰ����x��y�Ƿ��Ǻϸ�ģ������У����Լ�С�������Ƿ�����ظ�����
{
	int i, j;
	for (i = 0; i < 9; i++) // ���y ��
	{
		if (i != x && board[i][y] == board[x][y]) //�������е�ͬһ�����ϳ�����ͬ����
			return false;
	}
	
	for (j = 0; j < 9; j++) // ���x ��
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
			if (board[i][j] == '.')  //��������board�������ո񣬾Ͱ�1��9���ȥ��
			{
				for (int k = 0; k < 9; ++k)
				{
					board[i][j] = '1' + k;
					if (isValid(board, i, j) && solve(board)) //�ݹ����
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