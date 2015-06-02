#include<vector>
//��Ŀ����������һ��sudoku���ж����Ƿ��Ǻϸ��sudoku����ÿһ�к�ÿһ���У�����1-9ֻ�ܳ���һ�Σ���3*3�ĸ����У�����1-9Ҳֻ�ܳ���һ��
//�ⷨ��������һ���

bool checkUsed(std::vector<bool>& used, char c)//�жϵ�ǰ�ַ��Ƿ��Ѿ����ֹ�
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
		for (int j = 0; j < 9; ++j)//������Ƿ�����Ҫ��
		{
			if (checkUsed(used, board[i][j]))
				return false;
		}

		std::fill(used.begin(), used.end(), false);
		for (int j = 0; j < 9; ++j)//������Ƿ����Ҫ��
		{
			if (checkUsed(used, board[j][i]))
				return false;
		}
	}

	for (int row = 0; row < 3; ++row)//���9��С����
	{
		for (int col = 0; col < 3; ++col)
		{
			std::fill(used.begin(), used.end(), false);
			for (int i = col * 3; i < col * 3 + 3; ++i)//���һ������
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